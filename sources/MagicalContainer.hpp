#include <vector>
using namespace std;
namespace ariel
{
    bool isPrime(int number);

    class MagicalContainer
    {
    private:
        vector<int> element;
        vector<int*>primeElement; 

    public:
        ~MagicalContainer();
        MagicalContainer();
        void addElement(int);
        size_t size() const;
        void sortVector();
        void removeElement(int);
        void removePrimeElement(int*);
        vector<int> getElements() const;

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t currIndex;

        public:
            //AscendingIterator();
            ~AscendingIterator();
            AscendingIterator operator&(AscendingIterator &&) = delete;
            AscendingIterator(MagicalContainer &);
            AscendingIterator(MagicalContainer &, size_t);
            AscendingIterator(const AscendingIterator &);
            AscendingIterator begin();
            AscendingIterator end();
            int operator*() const;
            bool operator!=(const AscendingIterator &) const;
            bool operator==(const AscendingIterator &) const;
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator<(const AscendingIterator &) const;
            bool operator>(const AscendingIterator &) const;
            AscendingIterator &operator++();
        };
        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t currIndex;

        public:
            SideCrossIterator();
            ~SideCrossIterator();
            SideCrossIterator(MagicalContainer &, size_t);
            SideCrossIterator(MagicalContainer &);
            SideCrossIterator begin();
            SideCrossIterator end();

            SideCrossIterator operator&(SideCrossIterator &&) = delete;
            int operator*() const;
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator!=(const SideCrossIterator &) const;
            bool operator==(const SideCrossIterator &) const;
            bool operator<(const SideCrossIterator &) const;
            bool operator>(const SideCrossIterator &) const;
            SideCrossIterator &operator++();
        };
        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t currIndex;

        public:
            PrimeIterator();
            ~PrimeIterator();
            PrimeIterator operator&(PrimeIterator &&) = delete;
            PrimeIterator(MagicalContainer &, size_t);
            PrimeIterator(MagicalContainer &);
            PrimeIterator begin();
            PrimeIterator end();
            int operator*() const;
            bool operator!=(const PrimeIterator &) const;
            PrimeIterator &operator++();
            PrimeIterator &operator=(const PrimeIterator &other);

            bool operator==(const PrimeIterator &) const;
            bool operator<(const PrimeIterator &) const;
            bool operator>(const PrimeIterator &) const;
        };
    };
}