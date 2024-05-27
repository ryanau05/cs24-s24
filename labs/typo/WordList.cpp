#include "WordList.h"
#include "Point.h"
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
    // std::vector<Point> test = {{2.473, 1.087}, {7.160, 0.320},  {3.238, 0.737},  {3.491, 0.732},  {7.229, -0.329},  {2.225, 2.045},  {5.761, 0.314},  {7.833, 0.907},  {4.048, 0.331}};
    for (auto& word: mWords){
        if (word.size() == points.size()){
            float px, py, qx, qy;
            float dist;
            float letterScore;
            float totalScore = 0;
            float avgScore;

            for (size_t i = 0; i < points.size(); i++){
                px = points.at(i).x;
                py = points.at(i).y;
                qx = QWERTY[word[i] - 'a'].x;
                qy = QWERTY[word[i] - 'a'].y;
                dist = sqrt(pow((px - qx), 2) + pow((py - qy), 2));
                letterScore = 1 / ((10 * pow(dist, 2)) + 1);
                totalScore += letterScore;
            }

            avgScore = totalScore / points.size();
            if (heap.count() != heap.capacity()){
                heap.push(word, avgScore);
            }
            else if (heap.top().score < avgScore){
                heap.pushpop(word, avgScore);
            }
        }
    }
    while (true){
        if (heap.count() > 0){
            if (heap.top().score < cutoff){
                heap.pop();
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }
    return heap;
}