class Solution {
public:

    const vector<string> belowTwenty = {
        "Zero", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    const vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    const vector<string> thousands = {
        "", "Thousand", "Million", "Billion"
    };

    string convertBelowHundred(int number) {
        if (number < 20) {
            return belowTwenty[number];
        } else {
            int ten = number / 10;
            int unit = number % 10;
            return tens[ten] + (unit ? " " + belowTwenty[unit] : "");
        }
    }

    string convertBelowThousand(int number) {
        if (number < 100) {
            return convertBelowHundred(number);
        } else {
            int hundred = number / 100;
            int rest = number % 100;
            return belowTwenty[hundred] + " Hundred" + (rest ? " " + convertBelowHundred(rest) : "");
        }
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        string words;
        int thousandCounter = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                words = convertBelowThousand(num % 1000) + " " + thousands[thousandCounter] + (words.empty() ? "" : " ") + words;
            }
            num /= 1000;
            thousandCounter++;
        }
        if(words[words.size()-1]==' '){
            words.pop_back();
        }

        return words;
    }
};