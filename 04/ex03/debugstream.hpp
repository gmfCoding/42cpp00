/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugstream.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:06:16 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 02:07:52 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DEBUGSTREAM_HPP
# define DEBUGSTREAM_HPP
#  ifdef DEBUG_STREAM
#   define debugStream std::cout
# else
#  define debugStream std::ostream(0)
# endif
#endif