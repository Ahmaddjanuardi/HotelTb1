#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

// Menyimpan data pemesanan kamar
struct BookingData
{
    string name;
    int roomNumber;
    string roomType;
    string roomFacilities;
    int quantity;
    int nights;
};

// Vektor untuk menyimpan semua data pemesanan kamar 
vector<BookingData> bookings;

void showWelcomeScreen() {
    // Tampilkan pesan selamat datang
    cout << "======================================" << endl;
    cout << "       Welcome to Hotel Management     " << endl;
    cout << "======================================" << endl;
    cout << endl;
    cout << "         [1] Book a Room              " << endl;
    cout << "         [2] Check Out                " << endl;
    cout << "         [3] View Room Status         " << endl;
    cout << "         [4] Exit                     " << endl;
    cout << endl;
}

void bookingRoom() {
    // Tampilkan kamar yang ingin dibooking
    cout << "======================================" << endl;
    cout << "               Book a Room             " << endl;
    cout << "======================================" << endl;
    cout << endl;
    cout << "              [1] Standart Room        " << endl;
    cout << "              [2] Superior Room        " << endl;
    cout << "              [3] Deluxe Room        " << endl;
    cout << "              [4] Single Room        " << endl;
    cout << "              [5] Double Room        " << endl;
    cout << endl;

    int roomChoice;
    cout << "Enter room choice: ";
    cin >> roomChoice;

    // Meminta jumlah kamar yang diinginkan
    int quantity;
    cout << "Enter quantity: ";
    cin >> quantity;

    // Meminta jumlah malam menginap
    int nights;
    cout << "Enter number of nights: ";
    cin >> nights;

    string roomType;
    int pricePerNight;
    string roomFacilities;

    // Tampilkan informasi kamar berdasarkan pilihan pengguna
    switch (roomChoice) {
    case 1:
        roomType = "Standart Room Invormation";
        roomFacilities = "Facilities: TV, Wi-Fi, Air conditioning";
        pricePerNight = 100;
        break;
    case 2:
        roomType = "Superior Room Invormation";
        roomFacilities = "Facilities: TV, Wi-Fi, Air conditioning, Mini bar";
        pricePerNight = 150;
        break;
    case 3:
        roomType = "Deluxe Room Invormation";
        roomFacilities = "Facilities: TV, Wi-Fi, Air conditioning, Mini bar, Jacuzzi";
        pricePerNight = 200;
        break;
    case 4:
        roomType = "Single Room Invormation";
        roomFacilities = "Facilities: TV, Wi-Fi";
        pricePerNight = 80;
        break;
    case 5:
        roomType = "Double Room Invormation";
        roomFacilities = "Facilities: TV, Wi-Fi, Air conditioning";
        pricePerNight = 120;;
        break;
    default:
        cout << "Invalid room choice." << endl;
        break;
    }
    // Meminta data pemesan
    BookingData booking;
    cout << "Enter your name: ";
    cin.ignore(); // Menghindari masalah getline setelah cin
    getline(cin, booking.name);
    booking.roomType = roomType;
    booking.quantity = quantity;
    booking.nights = nights;
    booking.roomFacilities = roomFacilities;

    //simpan data pemesanan ke dalam victor
    bookings.push_back(booking);

    // Tampilkan data booking
    cout << "======================================" << endl;
    cout << "         Booking Data                  " << endl;
    cout << "======================================" << endl;
    cout << "Name: " << booking.name << endl;
    cout << "Room Type: " << booking.roomType << endl;
    cout << "Facilities: " << booking.roomFacilities << endl;
    cout << "Quantity: " << booking.quantity << endl;
    cout << "Nights: " << booking.nights << endl;
    cout << "Total Price: $" << (quantity * nights * pricePerNight) << endl;
}

void viewRoomStatus() {
    //Tampilkan data pesanan yang sedang berlangsung
    cout << "======================================" << endl;
    cout << "          Room Status                 " << endl;
    cout << "======================================" << endl;
    for (size_t i = 0; i < bookings.size(); i++)
    {
        cout << "Booking " << i + 1 << ":" << endl;
        cout << "Name: " << bookings[i].name << endl;
        cout << "Room Type: " << bookings[i].roomType << endl;
        cout << "Facilities: " << bookings[i].roomFacilities << endl;
        cout << "Quantity: " << bookings[i].quantity << endl;
        cout << "Nights: " << bookings[i].nights << endl;
        //Menghitung sisa waktu menginap
        int remainingNights = bookings[i].nights;
        if (remainingNights > 0)
        {
            cout << "Remaining Nights: " << remainingNights << endl;
        }
        else
        {
            cout << "Check out today" << endl;
        }
        cout << endl;
    }
}
// Fungsi untuk mendapatkan harga per malam berdasarkan tipe kamar
int getPricePerNight(const string& roomType) {
    // Lakukan pemetaan antara tipe kamar dan harga per malam
    if (roomType == "Standard Room") {
        return 100;
    }
    else if (roomType == "Superior Room") {
        return 150;
    }
    else if (roomType == "Deluxe Room") {
        return 200;
    }
    else if (roomType == "Single Room") {
        return 80;
    }
    else if (roomType == "Double Room") {
        return 120;
    }
    else {
        // Tipe kamar tidak valid, kembalikan harga default
        return 0;
    }
}

void checkOut() {
    // Meminta nama pemesan yang ingin check-out
    string nameToCheckOut;
    cout << "enter name to check out: ";
    cin.ignore(); //Menghindari masalah getline setelah cin
    getline(cin, nameToCheckOut);

    // Cari data pesanan yang sesuai dengan nama pesanan
    for (auto it = bookings.begin(); it != bookings.end(); ++it)
    {
        if (it->name == nameToCheckOut) {
            //Menampilkan informasi pesanan yang akan check-out
            cout << "======================================" << endl;
            cout << "       Checking Out Information        " << endl;
            cout << "======================================" << endl;
            cout << "Name: " << it->name << endl;
            cout << "Room Type: " << it->roomType << endl;
            cout << "Quantity: " << it->quantity << endl;
            cout << "Nights: " << it->nights << endl;
            cout << "Total Price: $" << (it->quantity * it->nights * getPricePerNight(it->roomType)) << endl;

            // Menghapus data pesanan setelah check-out
            bookings.erase(it);
            cout << "Check-out successful!" << endl;
            return;

       }
    }
    // Jika tidak ditemukan pesanan dengan nama pemesan yang dimasukkan
    cout << "No booking found with the given name." << endl;
}

void processCheckOut() {
    // Tampilkan data pesanan sebelum melakukan check-out
    viewRoomStatus();

    // Proses check-out
    checkOut();
}
int main() {
    int choice;

    do {
        // Tampilkan layar selamat datang
        showWelcomeScreen();

        // Meminta pengguna untuk memilih opsi
        cout << "Enter your choice: ";
        cin >> choice;

        // Proses pilihan pengguna
        switch (choice) {
        case 1:
            // Kode untuk memilih dan memesan kamar
            bookingRoom();
            break;
        case 2:
            // Kode untuk proses check-out
            processCheckOut();
            break;
        case 3:
            // Kode untuk melihat status kamar
            viewRoomStatus();
            break;
        case 4:
            cout << "Exiting program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

        // Tunggu input pengguna sebelum melanjutkan
        system("pause");
        system("cls"); // Hapus layar untuk tampilan berikutnya
    } while (choice != 4);

    return 0;
}