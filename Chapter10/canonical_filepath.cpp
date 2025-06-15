#include <iostream>
#include <experimental/filesystem>

using namespace std;
using namespace experimental::filesystem;

int main()
{
    path p {"testdir/foobar.txt"};

    cout << "current_path    : " << current_path()     << '\n'
         << "absolute_path   : " << absolute(p)        << '\n'
         << "system_complete : " << system_complete(p) << endl;

    cout << path{"testdir"} / "foobar.txt" << endl;
error_code err1,err2,err3;
    cout << "canonical testdir   : "
         << canonical("foobar.txt", current_path() / "testdir",err1) << '\n'
         << "canonical testdir 2 : "
         << canonical(p, current_path() / "testdir/..",err2) << endl;

    try {
    cout << "equivalence: "
         << equivalent("testdir/foobar.txt",
                       "testdir/../testdir/foobar.txt") << endl;
    }  catch (filesystem_error err) {
        cout<<"equivalent error1: "<<err.code()<<";"<<err.what()<< endl;
    }

    cout << "equivalence: "
         << equivalent("testdir/foobar.txt",
                       "testdir/../testdir/foobar.txt",err3) << endl;
    cout<<"equivalent error: "<<err3.value()<<err3.message();


}
