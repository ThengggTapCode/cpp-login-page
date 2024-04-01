#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <conio.h>
using namespace std;

// hàm in màu cho chữ
void printColoredText(int textColor)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, textColor);
}

// hàm tạm thời dừng code
void tamThoiDungCode(int miliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(miliseconds));
}
// hàm đăng nhập
void dangNhap(string inpPW, string inpUSN)
{

    // mật khẩu, username đúng
    string validUSN = "user";
    string validPW = "123";

    bool dangNhapThanhCong = false;

    while (!dangNhapThanhCong)
    {
        printColoredText(9); // in chữ màu xanh dương nhạt
        // nhập thông tin tài khoản
        cout << " ===== NHAP USERNAME VA MAT KHAU DE DANG NHAP =====" << endl;
        cout << endl;
        cout << " NHAP USERNAME: ";
        cin >> inpUSN;
        cout << endl;
        cout << " NHAP MAT KHAU: ";
        cin >> inpPW;
        cout << endl;
        tamThoiDungCode(500);
        cout << " ===== DANG DANG NHAP... =====" << endl;
        cout << endl;
        tamThoiDungCode(500);

        // kiểm tra thông tin đăng nhập
        if (inpUSN == validUSN && inpPW == validPW)
        {                        // nếu đúng
            printColoredText(2); // in chữ màu xanh lá
            cout << " ===== DANG NHAP THANH CONG! CHAO MUNG QUAY TRO LAI " << validUSN << "! =====" << endl;
            cout << endl;
            dangNhapThanhCong = true;
            tamThoiDungCode(500);
            printColoredText(6); // in chữ màu vàng
            cout << " ===== BAM BAT KI PHIM NAO DE THOAT =====" << endl;
            cout << endl;
            getch();
            cout << " ===== DANG THOAT CHUONG TRINH... =====" << endl;
            cout << endl;
            tamThoiDungCode(500);
        }
        else
        {                        // nếu sai
            printColoredText(4); // in chữ màu đỏ
            if (inpUSN != validUSN)
            { // nếu sai username
                cout << " ===== NHAP SAI USERNAME! VUI LONG NHAP LAI =====" << endl;
                cout << endl;
            }
            else
            { // nếu sai mật khẩu
                cout << " ===== NHAP SAI MAT KHAU! VUI LONG NHAP LAI =====" << endl;
                cout << endl;
            }
        }
    }
}

// hàm đăng nhập tài khoản mới
void dangNhapTKMoi(string vUSN, string vPW)
{
    bool dangNhapThanhCong = false;
    string inpPW, inpUSN;

    while (!dangNhapThanhCong)
    {
        printColoredText(9); // in chữ màu xanh dương nhạt

        // nhập thông tin tài khoản
        cout << " ===== NHAP USERNAME VA MAT KHAU DE TIEP TUC =====" << endl;
        cout << endl;
        cout << " NHAP USERNAME: ";
        cin >> inpUSN;
        cout << endl;
        cout << " NHAP MAT KHAU: ";
        cin >> inpPW;
        cout << endl;
        tamThoiDungCode(500);
        cout << " ===== DANG DANG NHAP... =====" << endl;
        cout << endl;
        tamThoiDungCode(500);

        // kiểm tra thông tin vừa nhập
        if (inpUSN == vUSN && inpPW == vPW)
        {                        // nếu đúng hết
            printColoredText(2); // in chữ màu xanh lá
            cout << " ===== DANG NHAP THANH CONG! CHAO MUNG " << vUSN << "! =====" << endl;
            cout << endl;
            tamThoiDungCode(500);
            printColoredText(6); // in chữ màu vàng
            cout << " ===== BAM BAT KI PHIM NAO DE THOAT =====" << endl;
            cout << endl;
            getch();
            cout << " ===== DANG THOAT CHUONG TRINH... =====" << endl;
            cout << endl;
            dangNhapThanhCong = true;
        }
        else
        {                        // nếu sai
            printColoredText(4); // in chữ màu đỏ

            if (inpUSN != vUSN)
            { // nếu sai username
                cout << " ===== NHAP SAI USERNAME! VUI LONG NHAP LAI =====" << endl;
                cout << endl;
            }
            else
            { // nếu sai mật khẩu
                cout << " ===== NHAP SAI MAT KHAU! VUI LONG NHAP LAI =====" << endl;
                cout << endl;
            }
        }
    }
}

// hàm đăng ký tài khoản
void dangKy(string nPW, string nUSN, string cPW)
{
    bool dangKyThanhCong = false;

    while (!dangKyThanhCong)
    {
        printColoredText(9); // in chữ màu xanh dương nhạt

        // nhập thông tin tài khoản
        cout << " ===== NHAP USERNAME VA MAT KHAU MOI DE TAO TAI KHOAN =====" << endl;
        cout << endl;
        cout << " NHAP USERNAME MOI: ";
        cin >> nUSN;
        cout << endl;
        cout << " NHAP MAT KHAU MOI: ";
        cin >> nPW;
        cout << endl;
        cout << " XAC NHAN LAI MAT KHAU: ";
        cin >> cPW;
        cout << endl;
        tamThoiDungCode(500);
        cout << " ===== DANG TAO TAI KHOAN... =====" << endl;
        cout << endl;
        tamThoiDungCode(500);

        // kiểm tra mật khẩu đã xác nhận
        if (nPW == cPW)
        {
            printColoredText(2); // in chữ màu xanh lá
            cout << " ===== DANG KY TAI KHOAN THANH CONG! VUI LONG DANG NHAP DE TIEP TUC =====" << endl;
            cout << endl;
            tamThoiDungCode(500);
            dangNhapTKMoi(nUSN, nPW);
            dangKyThanhCong = true;
        }
        else
        {
            printColoredText(4); // in chữ màu đỏ
            cout << " ===== MAT KHAU VUA XAC NHAN KHONG TRUNG KHOP! VUI LONG NHAP LAI =====" << endl;
            cout << endl;
        }
    }
}
int main()
{
    bool nhapDungLuaChon = false;

    char luaChon;
    string inpPW, inpUSN, nPW, nUSN, cPW;
    while (!nhapDungLuaChon)
    {
        printColoredText(9); // in chữ màu xanh dương nhạt

        // màn hình lựa chọn
        tamThoiDungCode(500);
        cout << endl;
        cout << " |     NHAN PHIM 1: DANG NHAP             |" << endl;
        cout << " |     NHAN PHIM 2: DANG KY TAI KHOAN     |" << endl;
        cout << " |     NHAN PHIM 3: THOAT                 |" << endl;
        cout << endl;
        tamThoiDungCode(500);
        cout << " ===== VUI LONG NHAP LUA CHON THONG QUA CAC PHIM SO =====" << endl;
        cout << endl;
        cout << " NHAP LUA CHON TAI DAY: ";

        // nhập lựa chọn
        cin >> luaChon;
        cout << endl;
        tamThoiDungCode(500);

        // kiểm tra lựa chọn
        switch (luaChon)
        {
        case '1':
            nhapDungLuaChon = true;
            cout << " ===== BAN DA CHON DANG NHAP =====" << endl;
            cout << endl;
            tamThoiDungCode(500);
            dangNhap(inpPW, inpUSN);
            break;
        case '2':
            nhapDungLuaChon = true;
            cout << " ===== BAN DA CHON DANG KY TAI KHOAN =====" << endl;
            cout << endl;
            tamThoiDungCode(500);
            dangKy(nPW, nUSN, cPW);
            break;
        case '3':
            printColoredText(6); // in chữ màu vàng
            nhapDungLuaChon = true;
            cout << " ===== BAM BAT KI PHIM NAO DE THOAT =====" << endl;
            cout << endl;
            getch();
            cout << " ===== DANG THOAT CHUONG TRINH... =====" << endl;
            tamThoiDungCode(500);
            cout << endl;
            break;
        default:
            printColoredText(4); // in chữ màu đỏ
            cout << " ===== LUA CHON KHONG HOP LE, VUI LONG NHAP LAI =====" << endl;
            cout << endl;
            break;
        }
    }
    return 0;
}