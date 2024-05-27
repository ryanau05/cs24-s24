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
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    float dx = points[i].x - QWERTY[word[i] - 'A'].x;
                    float dy = points[i].y - QWERTY[word[i] - 'A'].y;
                    float distance = std::sqrt(dx * dx + dy * dy);
                    
                    float score = 1.0f / (10.0f * distance * distance + 1.0f);
                    
                    totalScore += score;
                }
            }
            
            float avgScore = totalScore / static_cast<float>(word.size());
            
            if (avgScore >= cutoff) {
                try {
                    heap.push(word, avgScore);
                } catch (const std::overflow_error&) {
                }
            }
        }
    }
    
    return heap;
}