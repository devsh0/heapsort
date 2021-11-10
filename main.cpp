#include <iostream>
#include <vector>

void max_heapify(std::vector<int>& vector, size_t i, size_t heap_size)
{
    auto left = 2 * i + 1;
    auto right = left + 1;
    auto largest = i;
    if (left < heap_size && vector[i] < vector[left])
        largest = left;
    if (right < heap_size && vector[largest] < vector[right])
        largest = right;
    if (largest != i)
    {
        std::swap(vector[i], vector[largest]);
        max_heapify(vector, largest, heap_size);
    }
}

void build_max_heap(std::vector<int>& vector)
{
    ssize_t downto = vector.size() / 2;
    for (; downto >= 0; --downto)
        max_heapify(vector, downto, vector.size());
}

void heapsort(std::vector<int>& vector)
{
    build_max_heap(vector);
    size_t heap_size = vector.size();
    for (auto i = heap_size - 1; i > 0; i--)
    {
        std::swap(vector[i], vector[0]);
        max_heapify(vector, 0, i);
    }
}

int main()
{
    std::vector<int> vector = {10, 2, 20, 5, 7, 10, 33, 100};
    heapsort(vector);
    return 0;
}
