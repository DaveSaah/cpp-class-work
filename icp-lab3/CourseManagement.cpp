/**
 * @author David Saah
 * @studentID 72522025
 */
#include <string>
#include <vector>
#include <iostream>

class Course;

class Student
{
private:
  std::string studentid;
  std::string name;
  std::vector<Course> courses;

public:
  /**
   * Default constructor
   */
  Student() {}

  /**
   * Initialises a student class with id and name
   *
   * @param id the student id
   * @param name the student name
   */
  Student(std::string id, std::string name);

  /**
   * Enrolls a student into a course
   *
   * @param course a course for the student to be enrolled in
   */
  void enrollCourse(Course &course);

  /**
   * Displays student details
   */
  void display();
};

class TeachingAssistant;

class Course
{
private:
  std::string courseCode;
  std::string courseName;
  std::vector<Student> students;
  TeachingAssistant *ta;

public:
  /**
   * Default constructor
   */
  Course() {}

  /**
   * Initialises a Course class with code and name
   *
   * @param code the course code
   * @param name the course name
   */
  Course(std::string code, std::string name);

  /**
   * Adds a student to a course
   *
   * @param student the student to be enrolled
   */
  void addStudent(Student const &student);

  /**
   * Adds a teaching assistant to a course
   *
   * @param ta the teaching assistant to be enrolled
   */
  void addTA(TeachingAssistant &ta);

  /**
   * Gets the course name
   *
   * @return the course name
   */
  std::string getCourseName();

  /**
   * Gets the course code
   *
   * @return the course code
   */
  std::string getCourseCode();

  /**
   * Gets the students enrolled in a course
   *
   * @return the students enrolled in the course
   */
  std::vector<Student> getStudents();
};

class TeachingAssistant
{
private:
  std::string taID;
  std::string taName;
  Course course;

public:
  /**
   * Default constructor
   */
  TeachingAssistant() {}

  /**
   * Initialises a teaching assistant with id and name
   *
   * @param id the TA's id
   * @param name the TA's name
   */
  TeachingAssistant(std::string id, std::string name);

  /**
   * Assigns a teaching assistant to a course
   *
   * @param course the course to assign the teaching assistant to
   */
  void assignTA(Course &course);

  /**
   * Gets the teaching assistant's name
   *
   * @return the teaching assistant's name
   */
  std::string getTaName() { return taName; }
};

class CourseManagement : public Student, public TeachingAssistant
{
private:
  Course course;

public:
  /**
   * Default constructor: sets the course to be managed
   *
   * @param course the course to be managed
   * @param ta the teaching assistant to be assigned to the course
   */
  CourseManagement(Course course, TeachingAssistant ta);

  /**
   * Assigns a student to a course
   *
   * @param student the student to be assigned
   */
  void assignStudentToCourse(Student student);

  /**
   * Gets course details
   */
  void getCourseDetails();
};

/* Student Implementation */

Student::Student(std::string id, std::string name)
{
  studentid = id;
  this->name = name;
}

void Student::enrollCourse(Course &course)
{
  courses.push_back(course); // add to student's list of courses
  std::cout << name << " has been enrolled in " << course.getCourseName() << std::endl;
  std::cout << "Student ID: " << studentid << std::endl;
  std::cout << std::endl;
}

void Student::display()
{
  std::cout << "    ";
  std::cout << "Student ID: " << studentid << std::endl;
  std::cout << "    ";
  std::cout << "Student Name: " << name << std::endl;
}

/* Course Implementation */
Course::Course(std::string code, std::string name)
{
  courseCode = code;
  courseName = name;
}

void Course::addStudent(Student const &student)
{
  students.push_back(student);
}

void Course::addTA(TeachingAssistant &ta)
{
  this->ta = &ta;
}

std::string Course::getCourseName() { return courseName; }
std::string Course::getCourseCode() { return courseCode; }
std::vector<Student> Course::getStudents() { return students; }

/* TeachingAssistant Implementation */
TeachingAssistant::TeachingAssistant(std::string id, std::string name)
{
  taID = id;
  taName = name;
}

void TeachingAssistant::assignTA(Course &course)
{
  course.addTA(*this);
  this->course = course;

  std::cout << taName << " has been assigned to " << course.getCourseName() << std::endl;
  std::cout << "Teaching Assistant ID: " << taID << std::endl;
  std::cout << std::endl;
}

/* CourseManagement Implementation */
CourseManagement::CourseManagement(Course course, TeachingAssistant ta) : TeachingAssistant(ta)
{
  this->course = course;
}

void CourseManagement::assignStudentToCourse(Student student) {
  course.addStudent(student);
  student.enrollCourse(course);
}

void CourseManagement::getCourseDetails()
{
  std::cout << "Course Code: " << course.getCourseCode() << std::endl;
  std::cout << "Course Name: " << course.getCourseName() << std::endl;
  std::cout << "Teaching Assistant: " << this->getTaName() << std::endl;
  std::cout << "Number of student(s) enrolled: " << course.getStudents().size() << std::endl;

  std::cout << "Students enrolled: " << std::endl;
  for (Student student : course.getStudents())
  {
    student.display();
    std::cout << "    -----------------" << std::endl;
  }
}

int main()
{
  // testing
  Student student1("72522025", "David Saah");
  Student student2("72522026", "Jane Doe");
  Course course1("CS101", "Introduction to Computer Science");
  TeachingAssistant ta1("72522021", "John Doe");
  CourseManagement cm1(course1, ta1);

  cm1.assignStudentToCourse(student1);
  cm1.assignStudentToCourse(student2);
  ta1.assignTA(course1);
  cm1.getCourseDetails();
}
