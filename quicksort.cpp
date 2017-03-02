#include <algorithm>
#include <ctime>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>
#include <Windows.h>

const int NUMBER_OF_DIGITS = 20;
const int FONT_SIZE = 20;
const int Y_OFFSET = 10;

HANDLE stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

struct Number
{
  Number(int xPos, int yPos, int val) : x(xPos),
                                        y(yPos),
                                        value(val) {}
  int x;
  int y;
  int value;
};

typedef std::unique_ptr<struct Number> unique_number_ptr;
typedef std::vector<unique_number_ptr> unique_number_ptr_vector;

void SetCursor(short int x, short int y)
{
  SetConsoleCursorPosition(stdOutHandle, COORD{ x, y });
}

void clearScreen(short int x, short int y)
{
  COORD topLeft = { x, y };
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;

  GetConsoleScreenBufferInfo(stdOutHandle, &screen);
  FillConsoleOutputCharacterA(stdOutHandle,
                             ' ',
                            screen.dwSize.X * screen.dwSize.Y,
                            topLeft,
                            &written);

  FillConsoleOutputAttribute(stdOutHandle,
                             FOREGROUND_GREEN |
                             FOREGROUND_RED |
                             FOREGROUND_BLUE,
                             screen.dwSize.X * screen.dwSize.Y,
                             topLeft,
                             &written);
  SetCursor(0, 0);
}

void drawPivot(unique_number_ptr &piv)
{
  SetCursor(piv->x, piv->y + Y_OFFSET);
  std::cout << '^';
  SetCursor(0, 0);
  Sleep(100);
}

void drawArray(unique_number_ptr_vector &input)
{
  clearScreen(0, 0);
  for (const auto &i : input)
    {
      for (int j = 1; j <= i->value; j++)
        {
          SetCursor(i->x, Y_OFFSET - j);
          std::cout << '|';
        }
    }
  SetCursor(0, 0);
}

void swapWithVisual(unique_number_ptr_vector &input,
                    int i, int j, unique_number_ptr &piv)
{
  std::swap(input[i], input[j]);

  int temp = input[j]->x;
  input[j]->x = input[i]->x;
  input[i]->x = temp;
  drawArray(input);
  drawPivot(piv);
}

int partition(unique_number_ptr_vector &input, int left, int right)
{
  drawArray(input);
  Sleep(500);

  int mid      = left + (right - left) / 2;
  int midValue = input[mid]->value;

  swapWithVisual(input, left, mid, input[left]);

  int i = left;
  for (int j = i + 1; j <= right; ++j)
    {
      if (input[j]->value <= midValue)
        {
          ++i;
          if (input[i]->value != input[j]->value)
            {
              swapWithVisual(input, i, j, input[left]);
            }
        }
    }
  swapWithVisual(input, left, i, input[i]);

  return i;
}

void quickSort(unique_number_ptr_vector &input, int left, int right)
{
  if (left < right)
    {
      int mid = partition(input, left, right);
      quickSort(input, left, mid - 1);
      quickSort(input, mid + 1, right);
    }
  return;
}

int main()
{
  srand(time(nullptr));

  HWND hWnd = GetConsoleWindow();
  SetConsoleTitle(L"QuickSort Demo");

  unique_number_ptr_vector numArray;
  std::string garbage;


  /* hide console cursor */
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = false;
  SetConsoleCursorInfo(stdOutHandle, &info);

 /* change font size */
  COORD fontsize = { FONT_SIZE, FONT_SIZE };
  CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
  GetCurrentConsoleFontEx(stdOutHandle, false, &font);
  font.dwFontSize = fontsize;
  SetCurrentConsoleFontEx(stdOutHandle, false, &font);

  for (int i = 0; i < NUMBER_OF_DIGITS; ++i)
    {
      int random_number = rand() % 9 + 1;
      numArray.push_back(unique_number_ptr(new Number(i, 0, random_number)));
    }
  quickSort(numArray, 0, numArray.size() - 1);
  drawArray(numArray);

  SetCursor(0, Y_OFFSET);
  std::cout << "Press enter to quit. ";
  while (!std::getline(std::cin, garbage)){}
}
