import matplotlib.pyplot as plt

input_sizes = [10, 100, 1000, 5000]
insertion_swaps = [15, 450, 25000, 125000]   
selection_swaps = [9, 99, 999, 4999]      
bubble_swaps = [20, 4950, 249500, 12497500]  

plt.plot(input_sizes, insertion_swaps, marker='o', label='Insertion Sort')
plt.plot(input_sizes, selection_swaps, marker='s', label='Selection Sort')
plt.plot(input_sizes, bubble_swaps, marker='^', label='Bubble Sort')

plt.xlabel('Input Size (n)')
plt.ylabel('Number of Swaps')
plt.title('Sorting Algorithms: Swaps vs Input Size')
plt.legend()
plt.grid(True)
plt.xscale('log')  
plt.yscale('log')  
plt.show()
