#include<deque>
#include<chrono>
#include<thread>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;

void deqInsert(int count) {
  deque<int> d;
  d.resize(count);
  for (int i = 0; i < count; i++) {
    d[i] = i;
  }
  cout << "Inserting into "<< count<< "-element deque: ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.insert(d.begin(), i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout<< fixed <<setprecision(10) << elapsed.count()<< "\n";

  ofstream fout("text.txt");
  fout << d[count - 1];
  fout.close();
}

void dequePB(int count) {
  deque<int> d;
  cout << "Deque push back " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.push_back(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << d[count-1];
  fout.close();
}

void dequePF(int count) {
  deque<int> d;
  cout << "Deque push front " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.push_front(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << d[count - 1];
  fout.close();
}

void dequeFind(int count) {
  deque<int> d;
  d.resize(count);
  for (int i = 0; i < count; i++) {
    d[i] = i;
  }
  for (int i = 0; i < d.size(); i++) {
    d[i] = i;
  }
  cout << "Find into " << count << "-elements deque: ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    find(d.begin(),d.end() ,i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << d[count - 1];
  fout.close();
}

void dequeTest() {
  cout << "DEQUE TEST\n";
  deqInsert(100);
  deqInsert(1000);
  deqInsert(10000);
  deqInsert(100000);
  cout << "\n";
  dequePB(1000);
  dequePB(10000);
  dequePB(100000);
  dequePB(1000000);
  dequePB(10000000);
  dequePB(100000000);
  cout << "\n";
  dequePF(1000);
  dequePF(10000);
  dequePF(100000);
  dequePF(1000000);
  dequePF(10000000);
  dequePF(100000000);
  cout << "\n";
  dequeFind(100);
  dequeFind(1000);
  dequeFind(10000);
  dequeFind(100000);
  cout << "\n";
}