#include <iostream>
#include <stack>
#include <string>
using namespace std;

class DocumentVersionControl
{
    stack<string> undoStack; // Stores previous versions
    stack<string> redoStack; // Stores undone versions

public:
    void edit(const string &version)
    {
        undoStack.push(version);   // Push new version
        while (!redoStack.empty()) // Clear redo stack
            redoStack.pop();
        cout << "Edited document: " << version << endl;
    }

    void undo()
    {
        if (undoStack.empty())
        {
            cout << "Nothing to undo." << endl;
            return;
        }
        redoStack.push(undoStack.top()); // Save the current version for redo
        undoStack.pop();
        cout << "Undo completed." << endl;
    }

    void redo()
    {
        if (redoStack.empty())
        {
            cout << "Nothing to redo." << endl;
            return;
        }
        undoStack.push(redoStack.top()); // Restore the undone version
        redoStack.pop();
        cout << "Redo completed." << endl;
    }

    void showCurrentVersion()
    {
        if (undoStack.empty())
        {
            cout << "Document is empty." << endl;
        }
        else
        {
            cout << "Current version: " << undoStack.top() << endl;
        }
    }
};

int main()
{
    DocumentVersionControl doc;

    doc.edit("Version 1: Initial draft");
    doc.edit("Version 2: Added introduction");
    doc.edit("Version 3: Corrected typos");

    doc.showCurrentVersion(); // Display latest version

    doc.undo();
    doc.showCurrentVersion(); // Display after undo

    doc.redo();
    doc.showCurrentVersion(); // Display after redo

    return 0;
}
