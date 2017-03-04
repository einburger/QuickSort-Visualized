#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

typedef std::vector<int> vector;

// The height of a tree with at maximum
// two children per node is log2(number of nodes).
// The white spaces between the nodes in a standard
// tree can be thought of as a tree itself flipped about
// the x. By realizing this, the indentation for each level
// is related to the number of leaves on each level of this
// upside down white-space tree divided by two.
// The space between the leaves is also similar to a tree
// in that the spaces increase by powers of 2. To have a parent
// node perfectly above two children nodes, the two children nodes
// must be seperated by an odd number of spaces.
void printTree(vector &v, int i, int depth)
{
  int tree_height = std::floor(std::log2(v.size() - 1));
  int indentation_level = std::pow(2, tree_height - depth + 1) / 2;
  int leaves_at_depth = std::pow(2, depth);
  int spaces_between_leaves = std::pow(2, tree_height - depth + 1) - 1;

  for (int j = 0; j < indentation_level; ++j)
    {
      std::cout << ' ';
    }
  for (int n = 0; n < leaves_at_depth; ++n)
    {
      v[i] == -1 ? (std::cout << 'X') : (std::cout << v[i]);

      for (int m = 0; m < spaces_between_leaves; ++m)
        {
          std::cout<<" ";
        }
      ++i;

      if (i > v.size() - 1)
        {
          return;
        }
    }
  std::cout << '\n';
  printTree(v, i, depth + 1);
}

// Trees where the root is at index zero can be traversed
// by noting that the left child = 2*index + 1 and that
// the right child = 2*index + 2;
void makeBinary(vector& v, vector& v_out, int i, int j)
{
  if (i == v.size())
    {
      return;
    }
  else if (v_out[j] == -1)
    {
      v_out[j] = v[i];
      makeBinary(v, v_out, i + 1, 0);
    }
  else
    {
      v[i] > v_out[j] ? (j = 2*j + 2) : (j = 2*j + 1);
      if (j > v_out.size() - 1)
        {
          while (j > v_out.size() - 1)
            {
              v_out.push_back(-1);
            }
          v_out[j] = v[i];
          makeBinary(v, v_out, i + 1, 0);
        }
      else
        {
          makeBinary(v, v_out, i, j);
        }
    }
}

int main()
{
  srand( time(nullptr) );

  vector v;
  vector v_out;

  for (int i = 0; i < 5; ++i)
    {
      v.push_back(rand() % 9);
      v_out.push_back(-1);
    }

  printTree(v, 0, 0);
  std::cout << "\n\n";
  makeBinary(v, v_out, 0, 0);
  printTree(v_out, 0, 0);
}
