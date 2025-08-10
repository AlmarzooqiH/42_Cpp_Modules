/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:59:19 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/10 22:17:06 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdio.h>
# include <string>
# include <stdint.h>

	struct Data{
		std::string	contents;
		Data* next;
	};

	class Serializer{
		private:
			Serializer();
			Serializer(const Serializer& right);
			Serializer& operator=(const Serializer& right);
			~Serializer();

		public:
			static uintptr_t serializer(Data* ptr);
			static Data* deserialize(uintptr_t raw);
	};

#endif