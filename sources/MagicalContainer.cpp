#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
namespace ariel
{
    // help function
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
    MagicalContainer::MagicalContainer()
    {
    }
    MagicalContainer::~MagicalContainer()
    {
    }
    void MagicalContainer::sortVector()
    {
        std::sort(element.begin(), element.end());
    }
    void MagicalContainer::addElement(int element)
    {
        this->element.push_back(element);
        sortVector();
    }
    int MagicalContainer::size() const
    {
        return element.size();
    }
    void MagicalContainer::removeElement(int removed)
    {
        for (auto it = element.begin(); it != element.end(); ++it)
        {
            if (*it == removed)
            {
                element.erase(it);
                return;
            }
        }
        throw std::runtime_error("the element is not exist");
    }
    vector<int> MagicalContainer::getElements() const
    {
        return element;
    }

    //===========AscendingIterator Class================

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

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator ::begin()
    {
        return AscendingIterator(container, 0);
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator ::end()
    {
        return AscendingIterator(container, container.size());
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        return container.getElements().at(currIndex);
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (this != &other)
        {
            container = other.container;
            currIndex = other.currIndex;
        }
        return *this;
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
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator ::begin()
    {
        return SideCrossIterator(container, 0);
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator ::end()
    {
        return SideCrossIterator(container, container.size());
    }
    int MagicalContainer::SideCrossIterator::operator*() const
    {
        return container.getElements().at(currIndex);
    }
    bool MagicalContainer::SideCrossIterator ::operator!=(const SideCrossIterator &other) const
    {
        return !(this == &other);
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
        return PrimeIterator(container, container.size());
    }
    int MagicalContainer::PrimeIterator::operator*() const
    {
        return 0;
    }
    bool MagicalContainer::PrimeIterator ::operator!=(const PrimeIterator &other) const
    {
        return !(this == &other);
    }

    bool MagicalContainer::PrimeIterator ::operator==(const PrimeIterator &other) const
    {
        return &container == &other.container && currIndex == other.currIndex;
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (*this == end() || currIndex >= container.getElements().size())
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