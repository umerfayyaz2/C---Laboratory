#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
using namespace std;

class URLShortener
{
private:
    unordered_map<string, string> longToShort; // Maps long URLs to short codes
    unordered_map<string, string> shortToLong; // Maps short codes to long URLs
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int codeLength = 6;

    // Generate a random short code
    string generateShortCode()
    {
        string shortCode;
        for (int i = 0; i < codeLength; ++i)
        {
            shortCode += charset[rand() % charset.size()];
        }
        return shortCode;
    }

public:
    // Encode a long URL into a short code
    string encode(const string &longURL)
    {
        if (longToShort.find(longURL) != longToShort.end())
        {
            // If already encoded, return the existing short code
            return longToShort[longURL];
        }

        string shortCode;
        do
        {
            shortCode = generateShortCode();
        } while (shortToLong.find(shortCode) != shortToLong.end()); // Ensure the short code is unique

        // Store the mapping
        longToShort[longURL] = shortCode;
        shortToLong[shortCode] = longURL;

        return shortCode;
    }

    // Decode a short code back to the original long URL
    string decode(const string &shortCode)
    {
        if (shortToLong.find(shortCode) != shortToLong.end())
        {
            return shortToLong[shortCode];
        }
        return "Short code not found!";
    }
};

int main()
{
    URLShortener urlShortener;

    // Test cases
    string longURL1 = "https://www.example.com/long-url-1";
    string longURL2 = "https://www.anotherexample.com/super-long-url";

    // Encode URLs
    string shortCode1 = urlShortener.encode(longURL1);
    string shortCode2 = urlShortener.encode(longURL2);

    cout << "Original URL: " << longURL1 << " -> Short code: " << shortCode1 << endl;
    cout << "Original URL: " << longURL2 << " -> Short code: " << shortCode2 << endl;

    // Decode short codes
    cout << "Short code: " << shortCode1 << " -> Original URL: " << urlShortener.decode(shortCode1) << endl;
    cout << "Short code: " << shortCode2 << " -> Original URL: " << urlShortener.decode(shortCode2) << endl;

    // Attempt to decode an unknown short code
    cout << "Short code: ABC123 -> Original URL: " << urlShortener.decode("ABC123") << endl;

    return 0;
}
