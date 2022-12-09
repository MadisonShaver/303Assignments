#pragma once
#include <iostream>
#include <queue>
#include <map>
using namespace std;

void printQueue(queue<string> q);

void move_to_rear(queue<string> &q);

int palindrome(string a, int start, int end);

void printPalindrome(int b, string a);

void printCapitals(map<string, string> capitals);

void printUserCap(map<string, string> capitals);