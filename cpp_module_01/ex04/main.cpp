/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:07:40 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:22:18 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

inline std::string replace_line(const std::string &line, const std::string &src,
                                const std::string &dest) {
  std::string result;
  size_t index = 0;
  size_t end = 0;

  for (;;) {
    end = line.find(src, index);
    if (end == std::string::npos)
      break;
    result.append(line, index, end - index);
    index = end + src.size();
    result.append(dest);
  }
  result.append(line, index);

  return result;
}

inline int replace_file(const std::string &file, const std::string &src,
                        const std::string &dest) {

  std::ifstream in(file.c_str());
  if (in.fail()) {
    std::cerr << "Failed to open file " << file << ".\n";
    return 1;
  }

  std::ofstream out(std::string(file + ".replace").c_str());
  if (out.fail()) {
    std::cerr << "Failed to open file " << file << ".replace.\n";
    return 2;
  }

  std::string line;
  while (std::getline(in, line, '\n').good()) {
    out << replace_line(line, src, dest);
    if (in.eof() == false) {
      out << '\n';
    }
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cout << "Usage: ./sed [file] [find] [replace]\n";
    return 0;
  }
  return replace_file(std::string(argv[1]), std::string(argv[2]),
                      std::string(argv[3]));
}
