// testPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>

class Coordinate 
{
private:
    int position;

public:
    // Update set to return int for testing
 
    void set(const char *input)
    {
        if (input == nullptr || strlen(input) < 2)
        {
			position = -1; // Invalid input
            return;
		}
        int row;
        int col;

        if (isdigit(input[0]))
        {
            if (isdigit(input[1]))
            {
                position = -1; // Invalid input
                return;
			}
            row = (input[0]-'0')-1;
            col = ((int)tolower(input[1])%97);
        }
        else
        {
            if (!isdigit(input[1]))
            {
                position = -1; // Invalid input
				return;
			}
            col = ((int)tolower(input[0])%97);
			row = (input[1]-'0')-1;
        }

        if (row < 0 || row > 7 || col < 0 || col > 7)
		{
            position = -1; // Invalid input
            return;
		}
		position = row * 8 + col;
    }

    void test_set_a1()
    {
        // Use double quotes for string literal
        set("a1");
        assert(position == 0);
    }

    void test_set_c1()
    {
        set("c1");
        assert(position == 2);
	}

    void test_set_a9()
    {
		set("a9");
		assert(position == -1); // Invalid input
    }

    void test_set_nullptr()
    {
        set(nullptr);
        assert(position == -1); // Invalid input
	}

    void test_set_1a()
	{
		set("1a");
		assert(position == 0);
	}

    void test_set_C1()
    {
        set("C1");
        assert(position == 2);
	}

    void test_set_h8()
    {
        set("h8");
        assert(position == 63);
	}

    void test_set_aa()
    {
        set("aa");
        assert(position == -1); // Invalid input
	}

    void test_set_11()
    {
        set("11");
		assert(position == -1); // Invalid input
	}

    void testRunner()
    {
        test_set_a1();
        test_set_c1();
		test_set_a9();
		test_set_nullptr();
        test_set_1a();
		test_set_C1();
		test_set_h8();
		test_set_aa();
		test_set_11();
		std::cout << "All tests passed!" << std::endl;
	}

};

int main()
{
    Coordinate c;
    c.testRunner();
    return 0;
}
