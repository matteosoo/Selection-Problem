import random
import numpy as np
import os

# Input size (i) is  10000 to 30000 in steps 1000
for i in range(10000, 31000, 1000):
    # random choose k-th smallest
    k = np.random.randint(1, i+1)

    # random list is integers with range [1,20000]
    random_list = np.random.randint(1, 20000, i)
    
    file_name = 'input' + str(i) + '.txt'
    folder = 'data2/'
    # check whether the folder exist (python>=3.2)
    os.makedirs(folder, exist_ok=True)
    file_path = folder + file_name

    # open file
    fp = open(file_path, "w")

    # write to file
    fp.write(str(i))
    fp.write(' ')
    fp.write(str(k))
    fp.write('\n')
    for j in range(i):
        fp.write(str(random_list[j]))
        if j != len(random_list)-1:
            fp.write(' ')
    
    # close file
    fp.close()

    print(i, k)