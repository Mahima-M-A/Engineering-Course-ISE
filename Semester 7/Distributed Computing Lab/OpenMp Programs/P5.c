#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
#include<math.h>
#define K 4

int num_threads;
int num_points;
int points[50][2];
int cluster_centers[K][2] = {
    {75, 25}, {25, 25}, {25, 75}, {75, 75}
};
int cluster_count[K];

void populate_points() {
    int i;
    printf("\nGenerated datapoints:\n");
#pragma omp parallel for num_threads(num_threads)
    for (i = 0; i < num_points; i++) {
        points[i][0] = rand() % 100;
        points[i][1] = rand() % 100;
        printf("(%d, %d)\n", points[i][0], points[i][1]);
    }
    for (i = 0; i < K; i++) {
        cluster_count[i] = 0;
    }
}

double getDistance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    return (double)sqrt(dx * dx + dy * dy);
}

void classify_points() {
    int i;
    printf("\nClassification:\n");
#pragma omp parallel for num_threads(num_threads)
    for (i = 0; i < num_points; i++) {
        double min_dist = 1000, cur_dist = 1;
        int cluster_index = -1, j;
        for (j = 0; j < K; j++) {
            cur_dist = getDistance(points[i][0], points[i][1], cluster_centers[j][0], cluster_centers[j][1]);
            if (cur_dist < min_dist) {
                min_dist = cur_dist;
                cluster_index = j;
            }
        }
		printf("(%d, %d) is mapped to cluster_center (%d, %d) \n", points[i][0], points[i][1], cluster_centers[cluster_index][0], cluster_centers[cluster_index][1]);
        cluster_count[cluster_index]++;
    }
}

int main() {
	printf("Maximum number of threads: %d\n", omp_get_max_threads()); 
    printf("Enter number of points:\n");
    scanf("%d", &num_points);
    printf("Enter the number of threads:\n");
    scanf("%d", &num_threads);
    populate_points();
    double t1 = omp_get_wtime();
    classify_points();
    double t2 = omp_get_wtime();
    double t = (t2 - t1) * 1000;
    printf("Time Taken: %lfms", t);
	int i;
	printf("\nNumber of datapoints mapped to each cluster:\n");
	for(i = 0; i < K; i++) {
		printf("Cluster %d - %d\n", i+1, cluster_count[i]);
	}
	return 0;
}