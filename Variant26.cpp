/*********************************
 * Автор:    Хан Кирилл           *
 * Задание:  Обработка массивов   *
 * Вариант:  26                   *
 *********************************/

#include <iostream>

using namespace std;

int main() {
  const int maxSize = 20;
  double matrix[maxSize][maxSize];
  int orderedRowIndexes[maxSize];
  int rowCount = 0, columnCount = 0;
  int selectedRowIndex;
  int ascendingPairCount, descendingPairCount;
  int orderedRowCount = 0;
  double maximum = 0.0;

  cout << "Rows and columns (1-20): ";
  if (!(cin >> rowCount >> columnCount)) {
    cout << "INVALID";
    return 1;
  }
  if (rowCount < 1) {
    cout << "INVALID";
    return 1;
  }
  if (rowCount > maxSize) {
    cout << "INVALID";
    return 1;
  }
  if (columnCount < 1) {
    cout << "INVALID";
    return 1;
  }
  if (columnCount > maxSize) {
    cout << "INVALID";
    return 1;
  }

  cout << "Enter matrix row by row:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      if (!(cin >> matrix[rowIndex][columnIndex])) {
        cout << "INVALID";
        return 1;
      }
    }
  }

  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    ascendingPairCount = 0;
    descendingPairCount = 0;
    for (int columnIndex = 1; columnIndex < columnCount; ++columnIndex) {
      if (matrix[rowIndex][columnIndex] >= matrix[rowIndex][columnIndex - 1]) {
        ++ascendingPairCount;
      }
      if (matrix[rowIndex][columnIndex] <= matrix[rowIndex][columnIndex - 1]) {
        ++descendingPairCount;
      }
    }
    if (ascendingPairCount == columnCount - 1) {
      orderedRowIndexes[orderedRowCount] = rowIndex;
      ++orderedRowCount;
    } else {
      if (descendingPairCount == columnCount - 1) {
        orderedRowIndexes[orderedRowCount] = rowIndex;
        ++orderedRowCount;
      }
    }
  }

  if (orderedRowCount > 0) {
    selectedRowIndex = orderedRowIndexes[0];
    maximum = matrix[selectedRowIndex][0];
    for (int orderedRowIndex = 0; orderedRowIndex < orderedRowCount; ++orderedRowIndex) {
      selectedRowIndex = orderedRowIndexes[orderedRowIndex];
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
        if (matrix[selectedRowIndex][columnIndex] > maximum) {
          maximum = matrix[selectedRowIndex][columnIndex];
        }
      }
    }
  }

  cout << "Original matrix:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      if (columnIndex > 0) {
        cout << " ";
      }
      cout << matrix[rowIndex][columnIndex];
    }
    cout << endl;
  }

  cout << "Ordered rows:" << endl;
  if (orderedRowCount > 0) {
    for (int orderedRowIndex = 0; orderedRowIndex < orderedRowCount; ++orderedRowIndex) {
      selectedRowIndex = orderedRowIndexes[orderedRowIndex];
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
        if (columnIndex > 0) {
          cout << " ";
        }
        cout << matrix[selectedRowIndex][columnIndex];
      }
      cout << endl;
    }
    cout << "Maximum: " << maximum;
  } else {
    cout << "NONE" << endl << "Maximum: NONE";
  }

  return 0;
}
