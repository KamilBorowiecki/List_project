#include "pch.h"
#include "NodeList.cpp"


TEST(TEST_NodeList, AddingElements)
{
    NodeList<std::string> myList;


    myList.addElement("Jarek");
    myList.addElement("idk");
    myList.addElement("Szymon");
    myList.addElement("4");

    EXPECT_EQ("Jarek", myList.head->data);
    EXPECT_EQ("idk", myList.head->next->data);
    EXPECT_EQ("Szymon", myList.head->next->next->data);
    EXPECT_EQ("4", myList.head->next->next->next->data);
}

TEST(TEST_NodeList, FindElement)
{
    NodeList<std::string> myList;


    myList.addElement("Jarek");
    myList.addElement("idk");
    myList.addElement("Szymon");
    myList.addElement("4");

    EXPECT_EQ("Jarek", myList.findElement(1));
    EXPECT_EQ("idk", myList.findElement(2));
    EXPECT_EQ("Szymon", myList.findElement(3));
    EXPECT_EQ("4", myList.findElement(4));
}

TEST(TEST_NodeList, FindSpecificElement)
{
    NodeList<std::string> myList;


    myList.addElement("Jarek");
    myList.addElement("idk");
    myList.addElement("Szymon");
    myList.addElement("4");

    EXPECT_EQ("Jarek", myList.findSpecificElement("Jarek"));
    EXPECT_EQ("idk", myList.findSpecificElement("idk"));
    EXPECT_EQ("Szymon", myList.findSpecificElement("Szymon"));
    EXPECT_EQ("4", myList.findSpecificElement("4"));
}

TEST(TEST_NodeList, SerializationAndDesertialization)
{
    NodeList<std::string> myListS;
    NodeList<std::string> myListD;


    myListS.addElement("Jarek");
    myListS.addElement("idk");
    myListS.addElement("Szymon");
    myListS.addElement("4");

    myListS.serialization();
    myListD.deserialization();


    EXPECT_EQ(myListS.findElement(4), myListD.findElement(4));
    
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




