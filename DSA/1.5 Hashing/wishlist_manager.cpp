#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class WishlistManager
{
private:
    // Hash map to store user wishlist where the key is user_id, and the value is a set of product_ids
    unordered_map<int, unordered_set<int>> userWishlists;

public:
    // Function to add a product to a user's wishlist
    void addProductToWishlist(int userId, int productId)
    {
        userWishlists[userId].insert(productId);
    }

    // Function to check if a product is in the user's wishlist
    bool isProductInWishlist(int userId, int productId)
    {
        // Check if the product is in the user's wishlist
        return userWishlists[userId].find(productId) != userWishlists[userId].end();
    }

    // Function to remove a product from a user's wishlist
    void removeProductFromWishlist(int userId, int productId)
    {
        userWishlists[userId].erase(productId);
    }

    // Function to display the wishlist of a user (for testing)
    void displayWishlist(int userId)
    {
        cout << "Wishlist for User " << userId << ": ";
        for (int productId : userWishlists[userId])
        {
            cout << productId << " ";
        }
        cout << endl;
    }
};

int main()
{
    WishlistManager wm;

    // Add some products to users' wishlists
    wm.addProductToWishlist(1, 101);
    wm.addProductToWishlist(1, 102);
    wm.addProductToWishlist(2, 201);
    wm.addProductToWishlist(2, 202);

    // Display wishlists
    wm.displayWishlist(1); // Output: Wishlist for User 1: 101 102
    wm.displayWishlist(2); // Output: Wishlist for User 2: 201 202

    // Check if products are in the wishlist
    cout << "Is product 101 in User 1's wishlist? " << (wm.isProductInWishlist(1, 101) ? "Yes" : "No") << endl; // Yes
    cout << "Is product 103 in User 1's wishlist? " << (wm.isProductInWishlist(1, 103) ? "Yes" : "No") << endl; // No

    // Remove a product from a user's wishlist
    wm.removeProductFromWishlist(1, 101);
    wm.displayWishlist(1); // Output: Wishlist for User 1: 102

    return 0;
}
