#include "WordList.h"
#include <iostream>
#include <cctype>
#include <cmath>

WordList::WordList(std::istream& stream) {
    std::string word;
    while (std::getline(stream, word)) {
        bool valid = true;
        for (char c : word) {
            if (!std::islower(static_cast<unsigned char>(c))) {
                valid = false;
                break;
            }
        }
        if (valid) {
            mWords.push_back(word);
        }
    }
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const {
    Heap heap(maxcount);
    
    for (const auto& word : mWords) {
        if (word.size() == points.size()) {
            float totalScore = 0.0f;
            
            for (size_t i = 0; i < word.size(); ++i) {
                // Ensure the key exists in QWERTY layout
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    float dx = points[i].x - QWERTY[word[i] - 'A'].x;
                    float dy = points[i].y - QWERTY[word[i] - 'A'].y;
                    float distance = std::sqrt(dx * dx + dy * dy);
                    
                    // Apply scoring equation
                    float score = 1.0f / (10.0f * distance * distance + 1.0f);
                    
                    totalScore += score;
                }
            }
            
            // Calculate average score for the word
            float avgScore = totalScore / static_cast<float>(word.size());
            
            // Check if average score meets cutoff
            if (avgScore >= cutoff) {
                heap.push(word, avgScore);
            }
        }
    }
    
    return heap;
}