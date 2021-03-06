#include"parseXML.h"

using namespace std;

string rootname = "";
tree<string> *xml = new tree<string>(rootname);
bool flag = 1;

/*
Description : extracting closing or openning tag name
*/

string extract(int *left, string *mini)
{
    string s = *mini;
    string extractedtag = "";
    int i, start;
    i = 0;
    if (s[i + 1] != '/')
    {
        start = 0;
        while (s[i] != '>')
        {
            i++;
            (*left)++;
        }
        (*left)++;
    }
    else
    {
        start = 1;
        while (s[i] != '>')
            while (s[i] != '>')
            {
                i++;
                (*left)++;
            }
        (*left)++;
    }
    extractedtag = s.substr(start + 1, i - start - 1);
    return extractedtag;
}

/*
Description : extracting data
*/

string extractdata(int *left, string *mini)
{
    string s = *mini, data;
    int i = 0;
    int start = 0;
    while (s[i] != '<')
    {
        i++;
        (*left)++;
    }
    data = s.substr(start, i - start);
    return data;
}

/*
Description :
input to function minified XML we build the XML tree out of it.
*/

void parseXML(string &mini, tree<string> &xml)
{
    int right, left; //pointer to left and right of xml text (First character and last character in xml text)
    left = 0;
    right = mini.length() - 1;
    string tagname; 
    string data;
    if (flag)
    {
        int i = 1;
        while (mini[i] != '>')
        {
            i++;
        }
        rootname = mini.substr(1, i - 1);
        xml.data = rootname;
        mini = mini.substr(i + 1, right);
        right = mini.size();
        flag = 0;
    }
    else
    {
        while (right != -1)
        {
            if (mini[left] == '<')
            {
                if (mini[left + 1] == '/')
                {
                    tagname = extract(&left, &mini);
                    if (tagname == xml.data)
                    {
                        return;
                    }
                    mini = mini.substr(left, right);
                    right = mini.size() - 1;
                    left = 0;
                }
                else
                {
                    tagname = extract(&left, &mini);
                    tree<string> *child = new tree<string>(tagname);
                    xml.addChild(child);
                    mini = mini.substr(left, right);
                    parseXML(mini, *child);
                    left = 0;
                    right = mini.size() - 1;
                }
            }
            else
            {
                data = extractdata(&left, &mini);
                xml.addChild(data);
                mini = mini.substr(left, right);
                right = mini.size() - 1;
                return;
                tagname = extract(&left, &mini);
            }
        }
        parseXML(mini, xml);
    }
    parseXML(mini, xml);
}
