#include <iomanip>
#include <thread>

#include "matrix.h"
#include "randomnumgen.h"
#include "threadwork.h"

#define ROW_TEST 1500
#define COL_TEST 1500

const std::vector <size_t> th_n = {1, 4, 8, 16};

void start_n_threads(size_t n, thread_stat &result);

int main() {
	std::vector <thread_stat> stats(th_n.size());

	for (size_t i = 0; i < th_n.size(); ++i) {
		start_n_threads(th_n[i], stats[i]);
	}

	for (size_t i = 0; i < th_n.size(); ++i) {
		std::cout << std::fixed << std::setprecision(2) << std::setw(12)
		          << "Matrix " << ROW_TEST << "x" << COL_TEST << "\n"
							<< "\tSumm of columns minimal values: " << stats[i].min_col_sum << '\n'
							<< "\tNumber of threads: " << th_n[i] << '\n'
							<< "\tExecution time in secs: " << stats[i].exec_time.count() << '\n'
							<< "\tExecution time in millisecs: " << milliseconds(stats[i].exec_time).count() << '\n'
							<< "\tExecution time in microsecs: " << microseconds(stats[i].exec_time).count() << '\n';

		if (i == 0) { continue; }
	}
}

void start_n_threads(size_t n, thread_stat &result) {
	std::vector <std::thread> threads;
	std::vector <thread_stat> thread_stats(n);
	matrix <int> mtrx(ROW_TEST, COL_TEST);
	
	size_t col_step = COL_TEST / n;
	size_t col_start = 0;
	size_t col_end = col_step;

	for (size_t i = 0; i < n; ++i) {
		if (i == n - 1) {
			col_end = COL_TEST;
		}
		std::thread temp_thread(thread_func, std::ref(mtrx), col_start, col_end, std::ref(thread_stats[i]));
		threads.push_back(move(temp_thread));

		col_start += col_step;
		col_end += col_step;
	}
	for (size_t i = 0; i < threads.size(); ++i) {
		threads[i].join();
	}

	result.exec_time = thread_stats[0].exec_time;
	result.min_col_sum = thread_stats[0].min_col_sum;
	for (size_t i = 1; i < thread_stats.size(); ++i) {
		result.exec_time += thread_stats[i].exec_time;
		result.min_col_sum += thread_stats[i].min_col_sum;
	}
}
