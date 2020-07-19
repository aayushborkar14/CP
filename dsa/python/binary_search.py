def binary_search(input_array, value):
    array_len = len(input_array)
    if array_len%2 == 0:
        array1 = input_array[0:((array_len/2)+1)]
        array2 = input_array[((array_len+1)/2):(array_len)]
