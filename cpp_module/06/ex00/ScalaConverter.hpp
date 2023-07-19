#ifndef SCALACONVERTER_HPP
#define SCALACONVERTER_HPP

class ScalaConverter {
    private:
    	ScalaConverter();
		ScalaConverter(const ScalaConverter& copy);
		ScalaConverter& operator=(const ScalaConverter& copy);
	public:
		~ScalaConverter();
		static void convert(std::string str);
};

#endif
