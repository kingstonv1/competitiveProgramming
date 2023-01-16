#!/bin/python3

import math
import os
import random
import re
import sys

def isWeird(n):
    if n % 2 != 0:
        return "Weird"
    elif n in [2, 4]:
        return "Not Weird"
    elif (n % 2 == 0) and (5 < n < 21):
        return "Weird"
    elif (n % 2 == 0) and (n > 20):
        return "Not Weird"


if __name__ == '__main__':
    n = int(input().strip())
    print(isWeird(n))
