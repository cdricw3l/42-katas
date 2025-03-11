import pandas as pd
import seaborn as sns
import numpy as np

def main():
    data = np.loadtxt('Salary_dataset.csv', delimiter=',',dtype=str)

    header = data[0][1]
    
    #recuperer les ligne de 0-3 2D array:
    d = data[:3]
    print(d)
    print()
    print(data)
    
main()

# https://numpy.org/doc/2.2/user/absolute_beginners.html