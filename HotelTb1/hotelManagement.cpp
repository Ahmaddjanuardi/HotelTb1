#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

// Menyimpan data pemesanan kamar
struct BookingData
{
    string name;
    string roomType;
    int quantity;
    int nights;
};

// Struktur untuk menyimpan informasi tipe kamar
struct RoomInfo {
    string roomType;
    string roomFacilities;
    int pricePerNight;
};

// Vektor untuk menyimpan semua data pemesanan kamar 
vector<BookingData> bookings;

vector<RoomInfo> roomInfo = {
        {"Standard Room", "TV, Wi-Fi, Air conditioning", 100},
        {"Superior Room", "TV, Wi-Fi, Air conditioning, Mini bar", 150},
        {"Deluxe Room", "TV, Wi-Fi, Air conditioning, Mini bar, Jacuzzi", 200},
        {"Single Room", "TV, Wi-Fi", 80},
        {"Double Room", "TV, Wi-Fi, Air conditioning", 120}
};

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



// Fungsi untuk mendapatkan harga per malam berdasarkan tipe kamar
int getPricePerNight(const string& roomType, const vector<RoomInfo>& roomInfo) {
    // Lakukan pencarian di dalam vektor roomInfo untuk mendapatkan harga per malam berdasarkan tipe kamar
    for (const auto& info : roomInfo) {
        if (info.roomType == roomType) {
            return info.pricePerNight;
        }
    }
    // Jika tipe kamar tidak ditemukan, kembalikan harga default
    return 0;
}

// Fungsi untuk memproses pemesanan kamar
void bookingRoom(const vector<RoomInfo>& roomInfo, vector<BookingData>& bookings) {
    // Tampilkan kamar yang ingin dibooking
    cout << "======================================" << endl;
    cout << "               Book a Room             " << endl;
    cout << "======================================" << endl;
    cout << endl;
    // Tampilkan daftar tipe kamar dari vector roomInfo
    for (size_t i = 0; i < roomInfo.size(); i++) {
        cout << " [" << i + 1 << "] " << roomInfo[i].roomType << endl;
        cout << "     Facilities: " << roomInfo[i].roomFacilities << endl;
        cout << "     Price per Night: $" << roomInfo[i].pricePerNight << endl;
    }
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

    // Memilih tipe kamar berdasarkan pilihan pemesan
    if (roomChoice >= 1 && roomChoice <= roomInfo.size()) {
        const RoomInfo& chosenRoom = roomInfo[roomChoice - 1]; // Mengambil informasi tipe kamar yang dipilih

        // Meminta data pemesan
        string name;
        cout << "Enter your name: ";
        cin.ignore(); // Menghindari masalah getline setelah cin
        getline(cin, name);

        // Menampilkan informasi pemesanan
        cout << "======================================" << endl;
        cout << "         Booking Data                  " << endl;
        cout << "======================================" << endl;
        cout << "Name: " << name << endl;
        cout << "Room Type: " << chosenRoom.roomType << endl;
        cout << "Facilities: " << chosenRoom.roomFacilities << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Nights: " << nights << endl;
        // Menghitung dan menampilkan total harga pesanan
        cout << "Total Price: $" << (quantity * nights * getPricePerNight(chosenRoom.roomType, roomInfo)) << endl;

        // Simpan data pemesanan ke dalam vektor bookings
        BookingData booking;
        booking.name = name;
        booking.roomType = chosenRoom.roomType;
        booking.quantity = quantity;
        booking.nights = nights;
        bookings.push_back(booking); // Menambahkan data pemesanan ke vektor bookings
    }
    else {
        cout << "Invalid room choice." << endl;
    }
}

// Fungsi untuk memilih tipe kamar dan memulai proses pemesanan
void chooseRoomAndBook(const vector<RoomInfo>& roomInfo, vector<BookingData>& bookings) {
    // Memanggil fungsi bookingRoom dengan menggunakan vektor roomInfo
    bookingRoom(roomInfo, bookings);
}

void viewRoomStatus() {
    cout << "======================================" << endl;
    cout << "          Room Status                 " << endl;
    cout << "======================================" << endl;

    for (size_t i = 0; i < bookings.size(); i++) {
        cout << "Booking " << i + 1 << ":" << endl;
        cout << "Name: " << bookings[i].name << endl;
        cout << "Room Type: " << bookings[i].roomType << endl;
        cout << "Quantity: " << bookings[i].quantity << endl;
        cout << "Nights: " << bookings[i].nights << endl;

        // Mencari informasi fasilitas berdasarkan tipe kamar
        for (const auto& room : roomInfo) {
            if (room.roomType == bookings[i].roomType) {
                cout << "Facilities: " << room.roomFacilities << endl;
                break;
            }
        }

        int remainingNights = bookings[i].nights;
        if (remainingNights > 0) {
            cout << "Remaining Nights: " << remainingNights << endl;
        }
        else {
            cout << "Check out today" << endl;
        }

        cout << endl;
    }
}


void checkOut(const vector<RoomInfo>& roomInfo) {
    // Meminta nama pemesan yang ingin check-out
    string nameToCheckOut;
    cout << "Enter name to check out: ";
    cin.ignore(); // Menghindari masalah getline setelah cin
    getline(cin, nameToCheckOut);

    // Cari data pesanan yang sesuai dengan nama pemesan
    for (auto it = bookings.begin(); it != bookings.end(); ++it) {
        if (it->name == nameToCheckOut) {
            // Menampilkan informasi pesanan yang akan check-out
            cout << "======================================" << endl;
            cout << "       Checking Out Information        " << endl;
            cout << "======================================" << endl;
            cout << "Name: " << it->name << endl;
            cout << "Room Type: " << it->roomType << endl;
            cout << "Quantity: " << it->quantity << endl;
            cout << "Nights: " << it->nights << endl;
            cout << "Total Price: $" << (it->quantity * it->nights * getPricePerNight(it->roomType, roomInfo)) << endl;

            // Menghapus data pesanan setelah check-out
            bookings.erase(it);
            cout << "Check-out successful!" << endl;
            return;
        }
    }
    // Jika tidak ditemukan pesanan dengan nama pemesan yang dimasukkan
    cout << "No booking found with the given name." << endl;
}

void processCheckOut(const vector<RoomInfo>& roomInfo) {
    // Tampilkan data pesanan sebelum melakukan check-out
    viewRoomStatus();

    // Proses check-out
    checkOut(roomInfo); // Meneruskan roomInfo ke fungsi checkOut()
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
            chooseRoomAndBook(roomInfo, bookings);
            break;
        case 2:
            // Kode untuk proses check-out
            processCheckOut(roomInfo);
            break;
        case 3:
            // Kode untuk melihat status kamar
            viewRoomStatus();
            break;
        case 4:
            cout << "Exiting program. Thank you for booking in my hotel!" << endl;
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