#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
namespace ariel
{
    // help function that check if the number is prime
    bool isPrime(int number)
    {
        if (number <= 1)
        {
            return false;
        }
        for (int i = 2; i <= std::sqrt(number); ++i)
        {
            if (number % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    //==============MagicalContainer Class=======
    // constructor/D-ctor
    MagicalContainer::MagicalContainer()
    {
    }
    MagicalContainer::~MagicalContainer()
    {
    }
    //sort the element vector
    void MagicalContainer::sortVector()
    {
        std::sort(element.begin(), element.end());
    }

    //add new element to the vector
    void MagicalContainer::addElement(int element)
    {
        this->element.push_back(element);//add the element to the container
        sortVector();
        primeElement.clear();
        //add the primes number to PrimeVector
        for (size_t i = 0; i < this->element.size(); ++i)
        {
            if (isPrime(this->element.at(i)))
            {
                primeElement.push_back(&this->element.at(i));
            }
        }
    }
    //return the size of the container
    size_t MagicalContainer::size() const
    {
        return element.size();
    }
    //remove element from the primeVector 
    void MagicalContainer::removePrimeElement(int *prime)
    {
        for (auto it = primeElement.begin(); it != primeElement.end(); ++it)
        {
            if (*it == prime)
            {
                primeElement.erase(it);
                return;
            }
        }
    }
    //remove element from the container
    void MagicalContainer::removeElement(int removed)
    {
        bool prime = isPrime(removed);//to check if the number is a prime number
        bool exist = false;
        if (prime)
        {
            for (auto i = primeElement.begin(); i != primeElement.end(); i++)
            {
                if (**i == removed)
                {
                    removePrimeElement(*i);
                }
            }
        }
        for (auto it = element.begin(); it != element.end(); ++it)
        {
            if (*it == removed)
            {
                element.erase(it);
                exist = true;
                break;
            }
        }
        if (!exist)
        {
            throw std::runtime_error("the element is not exist");
        }
    }
    
    vector<int> MagicalContainer::getElements() const
    {
        return element;
    }

    //===========AscendingIterator Class================
        //C-tors/D-tor
    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
    }
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magicalContainer, size_t curr) : container(magicalContainer), currIndex(curr)
    {
    }
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magicalContainer) : container(magicalContainer), currIndex(0)
    {
    }

    MagicalContainer ::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), currIndex(other.currIndex)
    {
    }
        //Method to get an AscendingIterator pointing to the first element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator ::begin()
    {
        return AscendingIterator(container, 0);
    }
    //Method to get an AscendingIterator pointing one position past the last element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator ::end()
    {
        return AscendingIterator(container, container.size());
    }
    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const
    {

        return container.getElements().at(currIndex);
    }

    bool MagicalContainer::AscendingIterator ::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }
    bool MagicalContainer::AscendingIterator ::operator==(const AscendingIterator &other) const
    {
        return &container == &other.container && currIndex == other.currIndex;
    }
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return currIndex < other.currIndex;
    }
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return currIndex > other.currIndex;
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (&container != &other.container)
        { // throw error if we try to assign different containers
            throw runtime_error(" they belong to different containers.");
        }
        if (this != &other)
        {
            container = other.container;
            currIndex = other.currIndex;
        }
        return *this;
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (*this == end() || currIndex >= container.getElements().size())
        {
            throw runtime_error(" out of bounds!!");
        }
        currIndex++;
        return *this;
    }

    //==================SideCrossIterator Class==========
    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magicalContainer, size_t curr) : container(magicalContainer), currIndex(curr)
    {
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magicalContainer) : container(magicalContainer), currIndex(0)
    {
    }
    //Method to get an SideCrossIterator pointing to the first element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator ::begin()
    {
        return SideCrossIterator(container, 0);
    }
    //Method to get an SideCrossIterator pointing one position past the last element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator ::end()
    {
        return SideCrossIterator(container, container.size());
    }
    int MagicalContainer::SideCrossIterator::operator*() const
    {
        if (currIndex % 2 == 0)// if the index is even return the value from start
        {
            return container.getElements().at(currIndex / 2);
        }
        return container.getElements().at(container.size() - 1 - ((currIndex - 1) / 2));// if the index is odd return the value from the end
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (&container != &other.container)
        { // throw error if we try to assign different containers
            throw runtime_error(" they belong to different containers.");
        }
        if (this != &other)
        {
            container = other.container;
            currIndex = other.currIndex;
        }
        return *this;
    }
    bool MagicalContainer::SideCrossIterator ::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }
    bool MagicalContainer::SideCrossIterator ::operator==(const SideCrossIterator &other) const
    {
        return &container == &other.container && currIndex == other.currIndex;
    }
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return currIndex > other.currIndex;
    }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (*this == end() || currIndex >= container.getElements().size())
        {
            throw runtime_error(" out of bounds!!");
        }
        currIndex++;
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return currIndex < other.currIndex;
    }

    //==============PrimeIterator Class==========
    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magicalContainer, size_t curr) : container(magicalContainer), currIndex(curr)
    {
    }
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magicalContainer) : container(magicalContainer), currIndex(0)
    {
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator ::begin()
    {
        return PrimeIterator(container, 0);
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator ::end()
    {
        return PrimeIterator(container, container.primeElement.size());
    }
    int MagicalContainer::PrimeIterator::operator*() const
    {
        return *container.primeElement.at(currIndex);
    }
    bool MagicalContainer::PrimeIterator ::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator ::operator==(const PrimeIterator &other) const
    {
        return &container == &other.container && currIndex == other.currIndex;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (&container != &other.container)
        { // throw error if we try to assign different containers
            throw runtime_error(" they belong to different containers.");
        }
        if (this != &other)
        {
            container = other.container;
            currIndex = other.currIndex;
        }
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (  currIndex >= container.primeElement.size()||*this == end())
        {
            throw runtime_error(" out of bounds!!");
        }
        currIndex++;

        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return currIndex > other.currIndex;
    }
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return currIndex < other.currIndex;
    }
}