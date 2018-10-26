//
// Created by user on 26/10/18.
//

#ifndef PROJECT_LIBXT_LPI_H
#define PROJECT_LIBXT_LPI_H

/**
 * Print protocols when iptables -m ndpi -h is invoked
 *
 * @param cond 0 for enabled protocoles, 1 else
 * @return number of printed protocols
 */
static int lpi_print_prot_list(int cond);

#endif //PROJECT_LIBXT_LPI_H
