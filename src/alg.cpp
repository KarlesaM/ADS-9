// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream text(filename);
  BST<std::string> newTree;
  std::string slova = "";
  char raznic = 'i' - 'I';
  if (!text) {
    std::cout << "File is not found" << std::endl;
    return newTree;
  }
  while (!text.eof()) {
    char sim = text.get();
    if (sim >= 'I' && sim <= 'J') {
      sim = sim + raznic;
      slova = slova + sim;
    } else if (('j' >= sim) && ('i' <= sim)) {
      slova = slova + sim;
    } else {
      newTree.add(slova);
      slova = "";
    }
  }
  text.close();
  return newTree;
}
