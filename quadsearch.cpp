#include <ctime>
#include <iostream>
#include <random>
#include <vector>

// Finds a value in an nxn matrix where n = 2^k by recursing through each of the four
// quadrants of a 2d plane
struct COORD
{
  int x;
  int y;
};

void quadSearch(std::vector< std::vector<bool> > &grid, COORD start_point, COORD end_point)
{
  if (start_point.x < end_point.x &&
      start_point.y < end_point.y)
    {
      int width = ((end_point.x - start_point.x + 1) / 2);

      quadSearch(grid,
                 COORD {start_point.x,
                        start_point.y},
                 COORD {start_point.x + width - 1,
                        start_point.y + width - 1});

      quadSearch(grid,
                 COORD {start_point.x + width,
                        start_point.y},
                 COORD {start_point.x + (width * 2) - 1,
                        start_point.y + width - 1});

      quadSearch(grid,
                 COORD {start_point.x,
                        start_point.y + width},
                 COORD {start_point.x + width - 1,
                        start_point.y + (width * 2) - 1});

      quadSearch(grid,
                 COORD {start_point.x + width,
                        start_point.y + width},
                 COORD {start_point.x + (width * 2) - 1,
                        start_point.y + (width * 2) - 1});
    }

  if (grid[start_point.x][start_point.y])
    {
      std::cout << "found it at (" << start_point.x << ", " << start_point.y << ")";
    }
}

int main()
{
  srand(time(nullptr));

  int n = 1024;
  int random_x = rand() % n;
  int random_y = rand() % n;

  std::vector< std::vector<bool> > grid(n, std::vector<bool>(n, false));

  grid[random_x][random_y] = true;
  std::cout << "The coordinate is (" << random_x << ", " << random_y << ")\n";

  quadSearch(grid, COORD {0, 0}, COORD{n, n});
}
