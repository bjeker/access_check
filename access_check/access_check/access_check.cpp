/* access control in linux
uid and guid  are user and group id of user requesting operation on file
f is file id
p is requested operation
*/
#include <iostream>
using namespace std;

//access check function instantiation
int accesscheck(unsigned int uid, unsigned int guid, unsigned int p, int f);

//file permissions struct
typedef struct {

    unsigned int uid; // owner id

    unsigned int gid; // group id

    unsigned char u; // owner's permission

    unsigned char g; // group's permission

    unsigned char o; // other's permission

} Permission;

int main()
{
    /*run the access check
    * hard coded values for file input, can be changed to reflect user arguments for function
    */
    cout << accesscheck(2000, 2000, 2, 3);
}

Permission getPermission(int f)
{
    Permission perm;
    perm.uid = 1000;
    perm.gid = 2000;
    perm.u = 7;
    perm.g = 5;
    perm.o = 5;

    return perm;
}

//check if user can perform operation on file
int accesscheck(unsigned int uid, unsigned int gid, unsigned int p, int f)
{
    //check if owner of file
    if (uid == getPermission(f).uid)
    {
        //check if user permissions is same or higher
        if (p / getPermission(f).u >= 1)
        {
            //GRANTED
            return 1;
        }
        else
        {
            //DENIED
            return 0;
        }
    }
    //check if in group of file
    else if (gid == getPermission(f).gid)
    {
        //check if user permissions is same or higher
        if (p / getPermission(f).g >= 1)
        {
            //GRANTED
            return 1;
        }
        else
        {
            //DENIED
            return 0;
        }
    }
    //other
    else
    {
        //check if user permissions is same or higher
        if (p / getPermission(f).o >= 1)
        {
            //GRANTED
            return 1;
        }
        else
        {
            //DENIED
            return 0;
        }
    }
}