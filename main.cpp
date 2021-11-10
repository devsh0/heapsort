#include <iostream>
#include <random>
#include <vector>

std::random_device dev;
std::mt19937 rng(dev());

int random_number(int min = 1, int max = 100)
{
    std::uniform_int_distribution<std::mt19937::result_type> distribution(min, max);
    return distribution(rng);
}

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

std::vector<int> generate_vector()
{
    size_t size = random_number(5, 10);
    std::vector<int> vector;
    vector.reserve(size);

    for (int i = 0; i < size; i++)
        vector.push_back(random_number());
    return vector;
}

bool is_sorted(const std::vector<int>& vector)
{
    for (auto i = 0; i < vector.size() - 1; i++)
    {
        if (vector[i] > vector[i + 1])
            return false;
    }
    return true;
}

int main()
{
    for (int i = 0; i < 10000; i++)
    {
        auto vector = generate_vector();
        heapsort(vector);
        bool sorted = is_sorted(vector);
        if (!sorted) {
            std::cout << "Not sorted!\n";
            return 1;
        }
    }
    std::cout << "All vectors were sorted (Yay!)\n";
    return 0;
}
