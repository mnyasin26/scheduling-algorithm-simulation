#include "PrioSchedulingPreemptive.h"

#define TASK_LIMIT 10

void PrioSchedulingPreemptive()
{
    system("cls");

    // Inisialisasi
    int n;
    int option = 0;

    // lakukan selama option nya bukan 4
    do
    {
        printf("+====================================+\n");
        printf("|         PRIORITY SCHEDULING        |\n");
        printf("+------------------------------------+\n");
        printf("|              PREEMPTIVE            |\n");
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
            StrengthWeak(0);
            break;
        case 2:
            system("cls");

            // Tampilkan Kelemahan FCFS
            StrengthWeak(1);
            break;
        case 3:
            /**
             * p        = process/task
             * at       = arrival time
             * bt       = burst time
             * btt      = sisa burst time
             * ct       = completion time
             * tat      = turnaround time
             * wt       = waiting time
             * pr       = priority
             * awt      = rata-rata waiting time
             * atat     = rata-rata turn around time
             */
            int p[TASK_LIMIT], at[TASK_LIMIT], bt[TASK_LIMIT], btt[TASK_LIMIT], ct[TASK_LIMIT], tat[TASK_LIMIT], wt[TASK_LIMIT], vis[TASK_LIMIT] = {0}, i, j, temp = 0, n, pr[TASK_LIMIT];
            float awt = 0, atat = 0;
            printf("Masukkan jumlah proses yang ada ");
            scanf("%d", &n);
            printf("Masukkan %d Priority, Arrival Time dan Burst Time:\n", n);
            for (i = 0; i < n; i++)
            {
                p[i] = i + 1;
                scanf("%d %d %d", &pr[i], &at[i], &bt[i]);
                btt[i] = bt[i];
            }

            int ans = 0;
            j = 0;
            /**
             * j       = jumlah proses yang telah selesai
             * n       = total proses yang ada
             *
             */
            while (j < n)
            {
                int mn, idx;
                mn = idx = 1000000000;
                for (i = 0; i < n; i++)
                {
                    if (vis[i] == 0)
                    {
                        if (ans >= at[i] && mn > pr[i])
                        {
                            mn = pr[i];
                            idx = i;
                        }
                        else if (ans >= at[i] && mn == pr[i])
                        {
                            if (at[idx] > at[i])
                            {
                                mn = pr[i];
                                idx = i;
                            }
                        }
                    }
                }
                if (idx == 1000000000)
                {
                    ans++;
                }
                else
                {
                    ans++;
                    bt[idx]--;
                    if (bt[idx] == 0)
                    {
                        j++;
                        vis[idx] = 1;
                        ct[idx] = ans;
                    }
                }
            }

            // mengurutkan berdasarkan completion time
            for (i = 0; i < n; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (ct[i] > ct[j])
                    {
                        temp = ct[i];
                        ct[i] = ct[j];
                        ct[j] = temp;

                        temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;

                        temp = at[i];
                        at[i] = at[j];
                        at[j] = temp;

                        temp = bt[i];
                        bt[i] = bt[j];
                        bt[j] = temp;

                        temp = btt[i];
                        btt[i] = btt[j];
                        btt[j] = temp;

                        temp = tat[i];
                        tat[i] = tat[j];
                        tat[j] = temp;

                        temp = wt[i];
                        wt[i] = wt[j];
                        wt[j] = temp;

                        temp = pr[i];
                        pr[i] = pr[j];
                        pr[j] = temp;
                    }
                }
            }

            printf("\nProcess\t Priority\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time");
            for (i = 0; i < n; i++)
            {
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - btt[i];
                atat += tat[i];
                awt += wt[i];
            }

            atat = atat / n;
            awt = awt / n;
            for (i = 0; i < n; i++)
            {
                printf("\nP%d\t %d\t\t %d\t\t %d\t\t %d \t\t\t %d \t\t\t %d", p[i], pr[i], at[i], btt[i], ct[i], tat[i], wt[i]);
            }

            printf("\nRata-rata Turnaround Timenya adalah %f", atat);
            printf("\nRata-rata Waiting Timenya adalah %f", awt);
            printf("\nPress Any Key to Continue\n");
            getch();
        }
    } while (option != 4);
}

void StrengthWeak(int x)
{
    // tampilkan kelebihan PrioSchePreemp jika x = 0
    if (x == 0)
    {
        printf("+================================================================+\n");
        printf("|            KELEBIHAN PRIORITY SCHEDULING PREEMPTIVE            |\n");
        printf("+================================================================+\n");
        printf("| 1. Memenuhi kebijaksanaan yang ingin mencapai maksimasi suatu  |\n");
        printf("|    kriteria diterapkan.                                        |\n");
        printf("| 2. Dapat terjadi Starvation namun solusinya yaitu dengan Aging,|\n");
        printf("|    dengan meningkatkan prioritas dari setiap task              |\n");
        printf("|    yang menunggu dalam queue secara bertahap.                  |\n");
        printf("+================================================================+\n\n");
    }
    // tampilkan kekurangan PrioSchePreemp jika x = 1
    else if (x == 1)
    {
        printf("+================================================================+\n");
        printf("|            KEKURANGAN PRIORITY SCHEDULING PREEMPTIVE           |\n");
        printf("+================================================================+\n");
        printf("| 1. Dapat terjadinya indefinite (Starvation) yaitu              |\n");
        printf("|    adanya task yang sedang berjalan di task akan               |\n");
        printf("|    digantikan dengan task yang baru dan                        |\n");
        printf("|    berkesempatan tidak di jalankan karena selalu dikalahkan    |\n");
        printf("|    oleh task baru yang mempunyai prioritas lebih tinggi.       |\n");
        printf("|    Suatu task dengan prioritas yang rendah memiliki            |\n");
        printf("|    kemungkinan untuk tidak dieksekusi jika terdapat            |\n");
        printf("|    task lain yang memiliki prioritas lebih tinggi darinya.     |\n");
        printf("+================================================================+\n\n");
    }
}