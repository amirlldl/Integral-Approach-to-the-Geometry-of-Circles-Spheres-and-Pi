#include <stdio.h>
#include <gmp.h>
#include <time.h>
int main(){
	double start,end,ms_myalg;
	start = clock();
	mpf_set_default_prec(3500);
	mpf_t term, binom,pi,sqrt3,temp,half,temporary,sum;
	mpf_init_set_d(half,0.5);
	mpf_init(binom);
	mpf_set_ui(binom,1);
	mpf_init_set_ui(sqrt3,3);
	mpf_sqrt(sqrt3,sqrt3);
	mpf_init_set_ui(temp,1);
	mpf_init(term);
	mpf_init(pi);
	mpf_init(temporary);
	mpf_init(sum);
	for(int k = 0; k < 1700; k ++){
		mpf_set_ui(temp, 1);
		for(int i = 2*k + 1; i > 0; i--){
			mpf_mul(temp,temp,half);
		}
		mpf_div_ui(temp,temp, 2*k + 1);
		mpf_mul(term,binom,temp);
		if(k % 2 == 0){
			mpf_add(sum,sum,term);
		}
		else{
			mpf_sub(sum,sum,term);
		}
		mpf_sub_ui(temporary, half,k);
		mpf_div_ui(temporary,temporary, k + 1);
		mpf_mul(binom,binom,temporary);

	}
	mpf_mul_ui(sum,sum,12);
	mpf_mul_ui(sqrt3, sqrt3, 3); 
	mpf_div_ui(sqrt3, sqrt3, 2); 
	mpf_sub(pi,sum,sqrt3);
	end = clock();
	ms_myalg = ((double)end - start) / CLOCKS_PER_SEC * 1000;
	printf("Proposed method execution time: %f ms \n", ms_myalg);
	mpf_clears(term, binom, pi, sqrt3, temp, half, temporary, sum, NULL);
	start = clock();
	mpf_t num, den, base, sum_chud, pi_chud, constant, temp_chud, term_chud, lin_part, k_cubed;
    	mpf_init_set_ui(base, 13591409);
  	mpf_init_set_ui(sum_chud, 13591409);
  	mpf_inits(num, den, pi_chud, constant, temp_chud, term_chud, lin_part, k_cubed, NULL);

  	for (unsigned long k = 1; k < 72; k++) {
        	double n_val = -24.0 * (6.0 * k - 5.0) * (2.0 * k - 1.0) * (6.0 * k - 1.0);
        	mpf_set_d(num, n_val);

       		mpf_set_str(den, "262537412640768000", 10);
       		mpf_set_ui(k_cubed, k * k * k);
        	mpf_mul(den, den, k_cubed);

        	mpf_div(temp_chud, num, den);
        	mpf_mul(base, base, temp_chud);

        	double l_val = (13591409.0 + 545140134.0 * k) / 13591409.0;
        	mpf_set_d(lin_part, l_val);

        	mpf_mul(term_chud, base, lin_part);
        	mpf_add(sum_chud, sum_chud, term_chud);
    	}

    	mpf_set_ui(temp_chud, 10005);
    	mpf_sqrt(temp_chud, temp_chud);
    	mpf_mul_ui(constant, temp_chud, 426880);

    	mpf_div(pi_chud, constant, sum_chud);

   	end = clock();
   	double ms_chud = ((double)end - start) / CLOCKS_PER_SEC * 1000;
    	printf("Chudnovsky method execution time: %.2f ms\n", ms_chud);

    	mpf_clears(num, den, base, sum_chud, pi_chud, constant, temp_chud, term_chud, lin_part, k_cubed, NULL);

	return 0;
}

