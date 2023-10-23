import matplotlib.pyplot as plt

# Dados dos tempos de execução
sizes = [1000, 5000, 10000, 20000, 30000]

# Dados dos tempos para o BubbleSort, InsertionSort, SelectionSort e MergeSort
#Primeiro Teste
'''
bubble_crescente = [0.000667, 0.024333, 0.092, 0.365333, 0.888333]
bubble_decrescente = [0.002667, 0.065333, 0.216, 0.900333, 2.013667]
bubble_aleatorio = [0.002333, 0.051667, 0.231333, 1.004333, 2.353667]

insertion_crescente = [0.000, 0.000, 0.000, 0.000, 0.000]
insertion_decrescente = [0.001, 0.028, 0.107667, 0.439667, 0.975]
insertion_aleatorio = [0.000667, 0.014, 0.055, 0.231667, 0.487667]

selection_crescente = [0.001, 0.028333, 0.094667, 0.379, 0.872]
selection_decrescente = [0.001, 0.022667, 0.091, 0.368, 0.826667]
selection_aleatorio = [0.001, 0.023667, 0.096333, 0.382333, 0.855667]

merge_crescente = [0.000, 0.000333, 0.000667, 0.001667, 0.002333]
merge_decrescente = [0.000, 0.000333, 0.000667, 0.001, 0.002667]
merge_aleatorio = [0.000, 0.000333, 0.001333, 0.002667, 0.004333]
'''
#Segundo Teste
'''
bubble_crescente = [0.001000, 0.023333, 0.096000, 0.379333, 0.819667]
bubble_decrescente = [0.002000, 0.058000, 0.259333, 0.865000, 0.0]
bubble_aleatorio = [0.001667, 0.054000, 0.250333, 1.049667, 0.0]

insertion_crescente = [0.000000, 0.000000, 0.000000, 0.000000, 0.000000]
insertion_decrescente = [0.001000, 0.028000, 0.117000, 0.434333, 0.0]
insertion_aleatorio = [0.000667, 0.013667, 0.057000, 0.228333, 0.0]

selection_crescente = [0.001333, 0.027000, 0.097333, 0.382667, 0.855667]
selection_decrescente = [0.001000, 0.025333, 0.098333, 0.368000, 0.0]
selection_aleatorio = [0.000667, 0.024333, 0.098667, 0.387667, 0.0]

merge_crescente = [0.000000, 0.000667, 0.000667, 0.001000, 0.002333]
merge_decrescente = [0.000000, 0.000333, 0.000667, 0.001667, 0.002333]
merge_aleatorio = [0.000000, 0.000667, 0.001667, 0.002000, 0.004667]
'''
#Terceiro Teste
'''
bubble_crescente = [0.000667, 0.026000, 0.091000, 0.367000, 0.818667]
bubble_decrescente = [0.002333, 0.055000, 0.216667, 0.864333, 1.985667]
bubble_aleatorio = [0.002000, 0.051667, 0.230333, 1.002333, 2.324667]

insertion_crescente = [0.000000, 0.000000, 0.000000, 0.000000, 0.000333]
insertion_decrescente = [0.001333, 0.026667, 0.108333, 0.430000, 0.968333]
insertion_aleatorio = [0.000667, 0.013333, 0.054000, 0.216333, 0.487000]

selection_crescente = [0.001000, 0.024000, 0.094000, 0.385000, 0.851667]
selection_decrescente = [0.001000, 0.023000, 0.091333, 0.366667, 0.824667]
selection_aleatorio = [0.001000, 0.024000, 0.094667, 0.383333, 0.857667]

merge_crescente = [0.000000, 0.000333, 0.000667, 0.001333, 0.001667]
merge_decrescente = [0.000000, 0.000333, 0.000667, 0.001667, 0.002000]
merge_aleatorio = [0.000000, 0.000667, 0.001333, 0.002000, 0.004333]
'''
#Medias
bubble_crescente = [0.0003333333333333333, 0.007777666666666666, 0.032, 0.12644433333333333, 0.27322233333333334]
bubble_decrescente = [0.0006666666666666666, 0.019333333333333334, 0.08644433333333333, 0.28833333333333333, 0.0]
bubble_aleatorio = [0.0005556666666666667, 0.018, 0.08344433333333334, 0.34988899999999995, 0.0]

insertion_crescente = [0.0, 0.0, 0.0, 0.0, 0.0]
insertion_decrescente = [0.0003333333333333333, 0.009333333333333334, 0.039, 0.14477766666666667, 0.0]
insertion_aleatorio = [0.0002223333333333333, 0.004555666666666667, 0.019, 0.076111, 0.0]

selection_crescente = [0.0004443333333333333, 0.009, 0.03244433333333333, 0.12755566666666665, 0.2852223333333333]
selection_decrescente = [0.0003333333333333333, 0.008444333333333333, 0.03277766666666667, 0.12266666666666666, 0.0]
selection_aleatorio = [0.0002223333333333333, 0.008111, 0.032889, 0.12922233333333333, 0.0]

merge_crescente = [0.0, 0.000111, 0.0002223333333333333, 0.0005556666666666667, 0.0007776666666666666]
merge_decrescente = [0.0, 0.000111, 0.0002223333333333333, 0.0003333333333333333, 0.000889]
merge_aleatorio = [0.0, 0.000111, 0.0004443333333333333, 0.000889, 0.0014443333333333333]


# Gráfico para o BubbleSort
plt.figure(figsize=(10, 6))
plt.plot(sizes, bubble_crescente, label='BubbleSort - Ordem crescente', marker='o')
plt.plot(sizes, bubble_decrescente, label='BubbleSort - Ordem decrescente', marker='o')
plt.plot(sizes, bubble_aleatorio, label='BubbleSort - Vetor aleatório', marker='o')
plt.title('Desempenho do BubbleSort')
plt.xlabel('Tamanho do Vetor')
plt.ylabel('Tempo (segundos)')
plt.legend()
plt.grid(True)
plt.show()

# Gráfico para o InsertionSort

plt.figure(figsize=(10, 6))
plt.plot(sizes, insertion_crescente, label='InsertionSort - Ordem crescente', marker='o')
plt.plot(sizes, insertion_decrescente, label='InsertionSort - Ordem decrescente', marker='o')
plt.plot(sizes, insertion_aleatorio, label='InsertionSort - Vetor aleatório', marker='o')
plt.title('Desempenho do InsertionSort')
plt.xlabel('Tamanho do Vetor')
plt.ylabel('Tempo (segundos)')
plt.legend()
plt.grid(True)
plt.show()

# Gráfico para o SelectionSort
plt.figure(figsize=(10, 6))
plt.plot(sizes, selection_crescente, label='SelectionSort - Ordem crescente', marker='o')
plt.plot(sizes, selection_decrescente, label='SelectionSort - Ordem decrescente', marker='o')
plt.plot(sizes, selection_aleatorio, label='SelectionSort - Vetor aleatório', marker='o')
plt.title('Desempenho do SelectionSort')
plt.xlabel('Tamanho do Vetor')
plt.ylabel('Tempo (segundos)')
plt.legend()
plt.grid(True)
plt.show()

# Gráfico para o MergeSort
plt.figure(figsize=(10, 6))
plt.plot(sizes, merge_crescente, label='MergeSort - Ordem crescente', marker='o')
plt.plot(sizes, merge_decrescente, label='MergeSort - Ordem decrescente', marker='o')
plt.plot(sizes, merge_aleatorio, label='MergeSort - Vetor aleatório', marker='o')
plt.title('Desempenho do MergeSort')
plt.xlabel('Tamanho do Vetor')
plt.ylabel('Tempo (segundos)')
plt.legend()
plt.grid(True)
plt.show()
