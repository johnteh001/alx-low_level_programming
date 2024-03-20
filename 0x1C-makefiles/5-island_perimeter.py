#!/usr/bin/python3
""" Island Perimeter Module"""

def island_perimeter(grid):
    """Determines the perimeter os an insland"""
    pr = 0
    if len(grid) != 0:
        for row in range(len(grid)):
            for col in range(len(grid[row])):
                if grid[row][col] == 1:
                    if col == 0:
                        pr += 1
                    elif grid[row][col -1] == 0:
                        pr += 1
                        if col == (len(grid[row]) - 1):
                            pr += 1
                        elif grid[row][col + 1] == 0:
                            pr += 1
                            if row == 0:
                                pr += 1
                            elif grid[row -1][col] == 0:
                                pr += 1
                            if row ==(len(grid) - 1):
                                pr += 1
                            elif grid [row + 1][col] == 0:
                                pr += 1
        return 2*pr
