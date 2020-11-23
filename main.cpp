#pragma comment(linker, "/STACK:16777216")
#include<iostream>
#include"deque.h"
#include"vector.h"
#include"map.h"
#include"set.h"
#include"list.h"
#include"unordered_map.h"

using namespace std;

int main() {
  dequeTest();
  vectorTest();
  mapTest();
  setTest();
  listTest();
  unordered_map_test();
}