#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>

struct MarketState {
    double bid_ask_spread;
    double inventory_level;
};

class QLearningAgent {
private:
    double learning_rate = 0.05;
    double discount_factor = 0.99;
    std::unordered_map<uint64_t, std::vector<double>> q_table; 

public:
    int choose_action(uint64_t state_hash, bool explore) {
        if (q_table.find(state_hash) == q_table.end()) {
            q_table[state_hash] = {0.0, 0.0, 0.0};
        }

        if (explore) {
            return rand() % 3; 
        }
        
        auto& actions = q_table[state_hash];
        return std::distance(actions.begin(), std::max_element(actions.begin(), actions.end()));
    }

    void update_q_value(uint64_t state, int action, double reward, uint64_t next_state) {
        if (q_table.find(next_state) == q_table.end()) {
            q_table[next_state] = {0.0, 0.0, 0.0};
        }

        double current_q = q_table[state][action];
        double max_next_q = *std::max_element(q_table[next_state].begin(), q_table[next_state].end());
        
        q_table[state][action] = current_q + learning_rate * (reward + discount_factor * max_next_q - current_q);
    }
};

uint64_t hash_state(const MarketState& state) {
    return static_cast<uint64_t>(state.bid_ask_spread * 1000) ^ static_cast<uint64_t>(state.inventory_level);
}

int main() {
    std::cout << "[SYSTEM] Initializing Low-Latency RL Market Maker..." << std::endl;
    
    QLearningAgent agent;
    MarketState initial_state = {0.05, 10.0};
    uint64_t state_hash = hash_state(initial_state);

    int action = agent.choose_action(state_hash, true);
    std::cout << "[AGENT] Chose action: " << action << " (0: Hold, 1: Buy, 2: Sell)" << std::endl;

    double reward = 1.5; 
    MarketState next_state = {0.04, 11.0};
    uint64_t next_hash = hash_state(next_state);

    agent.update_q_value(state_hash, action, reward, next_hash);
    std::cout << "[SYSTEM] Q-Table updated successfully. Memory safe." << std::endl;

    return 0;
}