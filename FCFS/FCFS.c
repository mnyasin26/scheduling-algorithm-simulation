#include "FCFS.h"

#define MAX_PROCESS 100

void FCFS()
{
    system("cls");

    // Inisialisasi
    int n;
    int option = 0;

    // lakukan selama option nya bukan 4
    do
    {
        printf("+====================================+\n");
        printf("|       FIRST COME FIRST SERVE       |\n");
        printf("+------------------------------------+\n");
        printf("|           NON-PREEMPTIVE           |\n");
        printf("+====================================+\n");
        printf("|           --- Choose ---           |\n");
        printf("|           1. Kelebihan             |\n");
        printf("|           2. Kekurangan            |\n");
        printf("|           3. Simulasi              |\n");
        printf("|           4. Exit                  |\n");
        printf("+====================================+\n");
        printf("            Option: ");

        // masukkan pilihan dengan angka
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("cls");

            // Tampilkan Kelebihan FCFS
            minPlusFCFS(0);
            break;
        case 2:
            system("cls");

            // Tampilkan Kelemahan FCFS
            minPlusFCFS(1);
            break;
        case 3:
            system("cls");

            // SIMULATION FIRST COME FIRST SERVE //
            // Input
            printf("Masukkan jumlah proses: ");
            scanf("%d", &n);

            // Mulai Simulasi
            data fcfs[MAX_PROCESS];
            inputProcess(n, fcfs);

            // proses
            beginProcess(n, fcfs);

            // Output
            printProcess(n, fcfs);
            break;
        case 4:
            // exit(0);
        default:
            system("cls");
            printf("Invalid option!\n");
        }
    } while (option != 4);
}

void minPlusFCFS(int x)
{
    // tampilkan kelebihan fcfs jika x = 0
    if (x == 0)
    {
        printf("+================================================================+\n");
        printf("|               KELEBIHAN FIRST COME FIRST SERVE                 |\n");
        printf("+================================================================+\n");
        printf("| 1. Sederhana: Algoritma FCFS sangat mudah dipahami dan         |\n");
        printf("|    diimplementasikan karena hanya memerlukan satu antrian      |\n");
        printf("|    tunggal dan proses dikerjakan sesuai urutan kedatangan      |\n");
        printf("|    mereka.                                                     |\n");
        printf("| 2. Adil: Algoritma ini adil karena proses dikerjakan sesuai    |\n");
        printf("|    dengan urutan kedatangan. Oleh karena itu, proses yang      |\n");
        printf("|    datang lebih awal memiliki kesempatan yang sama untuk       |\n");
        printf("|    dijalankan.                                                 |\n");
        printf("| 3. Tanpa overhead: Algoritma FCFS tidak memerlukan overhead    |\n");
        printf("|    untuk mengatur penjadwalan atau mempertahankan data         |\n");
        printf("|    tambahan. Hal ini membuatnya lebih efisien dan mudah        |\n");
        printf("|    diimplementasikan pada sistem dengan sumber daya terbatas.  |\n");
        printf("+================================================================+\n\n");
    }
    // tampilkan kekurangan fcfs jika x = 1
    else if (x == 1)
    {
        printf("+================================================================+\n");
        printf("|               KEKURANGAN FIRST COME FIRST SERVE                |\n");
        printf("+================================================================+\n");
        printf("| 1. Tidak optimal: Algoritma FCFS tidak optimal karena tidak    |\n");
        printf("|    mempertimbangkan faktor waktu eksekusi proses. Jika proses  |\n");
        printf("|    yang lebih lama datang lebih awal, maka proses-proses lain  |\n");
        printf("|    harus menunggu lama untuk dijalankan.                       |\n");
        printf("| 2. Tidak adaptif: Algoritma ini tidak adaptif terhadap kondisi |\n");
        printf("|    sistem yang berubah-ubah. Jika ada proses yang membutuhkan  |\n");
        printf("|    waktu lebih lama dari yang diharapkan, algoritma ini tidak  |\n");
        printf("|    dapat menyesuaikan diri untuk mengurangi waktu tunggu       |\n");
        printf("|    proses-proses lain.                                         |\n");
        printf("| 3. Meningkatkan waktu rata-rata tunggu: Karena proses          |\n");
        printf("|    dikerjakan sesuai urutan kedatangan, maka waktu rata-rata   |\n");
        printf("|    tunggu bisa menjadi lebih lama jika proses-proses yang      |\n");
        printf("|    membutuhkan waktu lebih singkat harus menunggu              |\n");
        printf("|    proses-proses yang lebih lama untuk selesai.                |\n");
        printf("| 4. Dalam situasi tertentu, algoritma FCFS dapat digunakan      |\n");
        printf("|    dengan sangat baik, tetapi di sisi lain, kelemahan-kelemahan|\n");
        printf("|    yang dimilikinya dapat membuatnya menjadi kurang optimal    |\n");
        printf("|    dibandingkan dengan algoritma penjadwalan proses yang lebih |\n");
        printf("|    kompleks seperti Shortest Job First (SJF) atau              |\n");
        printf("|    Round Robin (RR).                                           |\n");
        printf("+================================================================+\n\n");
    }
}

void sorting(int n, data fcfs[], int x)
{
    // ascending
    int temp_pid;
    int temp_at;
    int temp_bt;
    int temp_wt;
    int temp_tuat;

    int i, j;

    for (i = 1; i < n; i++)
    {
        temp_pid = fcfs[i].pid;
        temp_at = fcfs[i].at;
        temp_bt = fcfs[i].bt;
        temp_wt = fcfs[i].wt;
        temp_tuat = fcfs[i].tuat;

        j = i - 1;

        if (x == 0)
        {
            // urut dari arrival time terkecil
            while ((temp_at < fcfs[j].at) && (j >= 0))
            {
                fcfs[j + 1].pid = fcfs[j].pid;
                fcfs[j + 1].at = fcfs[j].at;
                fcfs[j + 1].bt = fcfs[j].bt;
                fcfs[j + 1].wt = fcfs[j].wt;
                fcfs[j + 1].tuat = fcfs[j].tuat;

                j = j - 1;
            }
        }
        else if (x == 1)
        {
            // urut dari id terkecil
            while ((temp_pid < fcfs[j].pid) && (j >= 0))
            {
                fcfs[j + 1].pid = fcfs[j].pid;
                fcfs[j + 1].at = fcfs[j].at;
                fcfs[j + 1].bt = fcfs[j].bt;
                fcfs[j + 1].wt = fcfs[j].wt;
                fcfs[j + 1].tuat = fcfs[j].tuat;

                j = j - 1;
            }
        }

        fcfs[j + 1].pid = temp_pid;
        fcfs[j + 1].at = temp_at;
        fcfs[j + 1].bt = temp_bt;
        fcfs[j + 1].wt = temp_wt;
        fcfs[j + 1].tuat = temp_tuat;
    }
}

void inputProcess(int n, data fcfs[])
{
    for (int i = 0; i < n; i++)
    {
        fcfs[i].pid = i + 1;

        printf("Masukkan arrival time pada proses dengan id %d: ", fcfs[i].pid);
        scanf("%d", &fcfs[i].at);

        printf("Masukkan burst time pada proses dengan id %d: ", fcfs[i].pid);
        scanf("%d", &fcfs[i].bt);

        fcfs[i].wt = 0;
        fcfs[i].tuat = 0;
    }
}

void beginProcess(int n, data fcfs[])
{
    // sort berdasarkan waktu arrival paling kecil
    sorting(n, fcfs, 0);

    for (int i = 0; i < n; i++)
    {
        // untuk menghitung waiting time
        fcfs[i + 1].wt = fcfs[i].bt + fcfs[i].wt;

        // untuk menghitung turn around time
        fcfs[i].tuat = fcfs[i].bt + fcfs[i].wt;
    }

    // sort lagi berdasarkan id proses paling kecil (untuk tampilan)
    sorting(n, fcfs, 1);
}

void printProcess(int n, data fcfs[])
{
    float twt = 0.0; // total waiting time
    float awt;       // rata-rata waiting time

    float tat = 0.0; // total turn around time
    float att;       // rata-rata turn around time

    printf("+-----+--------------+------------+--------------+------------------+\n");
    printf("| PID | Arrival Time | Burst Time | Waiting Time | Turn Around Time |\n");
    printf("+-----+--------------+------------+--------------+------------------+\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %d", fcfs[i].pid);
        if ((n >= 10) && (i + 1 < 10))
        {
            printf("  ");
        }
        else
        {
            printf("   ");
        }

        printf("| %d", fcfs[i].at);
        if (fcfs[i].at < 10)
        {
            printf("            ");
        }
        else if ((fcfs[i].at >= 10) && (fcfs[i].at < 100))
        {
            printf("           ");
        }
        else if ((fcfs[i].at >= 100) && (fcfs[i].at < 1000))
        {
            printf("         ");
        }

        printf("| %d", fcfs[i].bt);
        if (fcfs[i].bt < 10)
        {
            printf("          ");
        }
        else if ((fcfs[i].bt >= 10) && (fcfs[i].bt < 100))
        {
            printf("         ");
        }
        else if ((fcfs[i].bt >= 100) && (fcfs[i].bt < 1000))
        {
            printf("        ");
        }

        printf("| %d", fcfs[i].wt);
        if (fcfs[i].wt < 10)
        {
            printf("            ");
        }
        else if ((fcfs[i].wt >= 10) && (fcfs[i].wt < 100))
        {
            printf("           ");
        }
        else if ((fcfs[i].wt >= 100) && (fcfs[i].wt < 1000))
        {
            printf("          ");
        }

        printf("| %d", fcfs[i].tuat);
        if (fcfs[i].tuat < 10)
        {
            printf("                ");
        }
        else if ((fcfs[i].tuat >= 10) && (fcfs[i].tuat < 100))
        {
            printf("               ");
        }
        else if ((fcfs[i].tuat >= 100) && (fcfs[i].tuat < 1000))
        {
            printf("              ");
        }

        // menghitung total waiting time
        twt = twt + fcfs[i].wt;

        // menghitung total turn around time
        tat = tat + (fcfs[i].wt + fcfs[i].bt);

        printf("|\n");
        printf("+-----+--------------+------------+--------------+------------------+\n");
    }

    // menghitung rata-rata waiting time
    awt = twt / n;

    // menghitung rata-rata turn around time
    att = tat / n;

    printf("Avg. waiting time     = %.1f\n", awt);
    printf("Avg. turn around time = %.1f\n\n", att);
}
