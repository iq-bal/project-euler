# project-euler

#include<bits/stdc++.h>
using namespace std;

class Media {
public:

  virtual void Play() = 0;
  virtual void Pause() = 0;
  virtual void Stop() = 0;

  virtual ~Media() {}
};

class Book : public Media {
private:
  string Title;
  string Author;
  int numberOfPages;

public:
  Book(string t, string a, int n) : Title(t), Author(a), numberOfPages(n) {}

  void Play(){
    cout << "Opening " << Title << " by " << Author << endl;
  }

  void Pause(){
    cout << "Bookmarking " << Title << endl;
  }

  void Stop(){
    cout << "Closing " << Title << endl;
  }

  friend ostream& operator<<(ostream& os, const Book& b) {
    os << "Book: " << b.Title << "\nAuthor: " << b.Author << "\nNumber of pages: " << b.numberOfPages;
    return os;
  }
};

class Movie : public Media {
private:
  string Title;
  string Director;
  int durationInMinutes;

public:
  Movie(string t, string d, int m) : Title(t), Director(d), durationInMinutes(m) {}

  void Play(){
    cout << "Playing " << Title << " by " << Director << endl;
  }

  void Pause(){
    cout << "Pausing " << Title << endl;
  }

  void Stop(){
    cout << "Stopping " << Title << endl;
  }

  friend ostream& operator<<(ostream& os, const Movie& m) {
    os << "Movie: " << m.Title << "\nDirector: " << m.Director << "\nDuration in minutes: " << m.durationInMinutes;
    return os;
  }
};

class Song : public Media {
private:
  string Title;
  string Artist;
  int durationInSeconds;

public:
  Song(string t, string a, int s) : Title(t), Artist(a), durationInSeconds(s) {}

  void Play(){
    cout << "Playing " << Title << " by " << Artist << endl;
  }

  void Pause(){
    cout << "Pausing " << Title << endl;
  }

  void Stop(){
    cout << "Stopping " << Title << endl;
  }

   friend ostream& operator<<(ostream& os, const Song& s) {
     os << "Song: " << s.Title << "\nArtist: " << s.Artist << "\nDuration in seconds: " << s.durationInSeconds;
     return os;
   }
};

template <typename T>
void showDetails(T x) {
  if (typeid(x) == typeid(Book)  typeid(x) == typeid(Movie)  typeid(x) == typeid(Song)) {
    cout << "It's a ";
    if(typeid(x) == typeid(Book))cout<<"Book"<<endl;
    else if(typeid(x) == typeid(Movie))cout<<"Movie"<<endl;
    else cout<<"Song"<<endl;
    cout << x << "\n";
  }
  else {
    cout << "It's not a media\n";
  }
}

int main() {
  
  Book b("data stucture and algorithm", "shakhawat hossain", 1178);
  Movie m("baba keno chakor", "The Wachowskis", 136);
  Song s("ghum", "Queen", 355);

  showDetails(b);
  showDetails(m);
  showDetails(s);
  showDetails(42);

}
