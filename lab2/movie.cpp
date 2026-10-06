#include "movie.h"
// Дата по умолчанию
ReleaseDate::ReleaseDate()
    : day(1), month(1), year(2026) {
}
// Дата с заданными значениями
ReleaseDate::ReleaseDate(int day, int month, int year)
    : day(day), month(month), year(year) {
    if (!isValid()) {
        this->day = 1;
        this->month = 1;
        this->year = 2026;}}
// Проверка даты
bool ReleaseDate::isValid() const {
    if (year <= 0 || month < 1 || month > 12 || day < 1) {
        return false;}
    // Февраль
    if (month == 2) {
        if (day > 28) {
            return false;}}
    // Месяцы, в которых 30 дней
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;}}
    // Остальные месяцы
    if (day > 31) {
        return false;}
    return true;}
    // Фильм по умолчанию
Movie::Movie()
    : title("Без названия"), duration(0), rating(0.0), releaseDate() {}

// Фильм с названием и продолжительностью
Movie::Movie(string title, int duration)
    : title(title), duration(duration), rating(0.0), releaseDate() {

    if (this->title.empty()) {
        this->title = "Без названия";}
    if (this->duration < 0) {
        this->duration = 0;}}
        
// Фильм со всеми заданными значениями
Movie::Movie(string title, int duration, double rating, ReleaseDate releaseDate)
    : title(title), duration(duration), rating(rating), releaseDate(releaseDate) {

    if (this->title.empty()) {
        this->title = "Без названия";}
    if (this->duration < 0) {
        this->duration = 0;}
    if (this->rating < 0 || this->rating > 10) {
        this->rating = 0.0;}}
