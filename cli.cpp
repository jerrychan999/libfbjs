#include <stdio.h>
#include <iostream>
#include <string.h>
#include "fbjs.hpp"
#include "parser.hpp"

int main(int argc, char* argv[]) {

  // Mutate
  Node* root = argc > 1 ? new NodeProgram(fopen(argv[1], "r")) : new NodeProgram(stdin);
  fbjsize_guts_t guts;
  guts.app_id = argc > 1 ? argv[1] : "123";
  guts.forinid = 0;
  root = fbjsize(root, &guts);

  // Render
  rope_t rendered = root->render(RENDER_PRETTY);
  delete root;
  std::cout<<rendered;
  printf("\n");
  return 0;

}