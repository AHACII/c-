#include "TRectangle.hpp"

TRectangle::TRectangle() : TObjetGraphique(), longueur(0), largeur(0) {}

TRectangle::TRectangle(const TRectangle &rec)
    : TObjetGraphique(rec), longueur(rec.longueur), largeur(rec.largeur) {}

TRectangle::~TRectangle() {}

void TRectangle::operator=(const TRectangle &rec) {
    if (this != &rec) {
        TObjetGraphique::operator=(rec);
        longueur = rec.longueur;
        largeur = rec.largeur;
    }
}

TRectangle::TRectangle(const TPoint &p, int _long, int _larg)
    : TObjetGraphique(p), longueur(_long), largeur(_larg) {}

int TRectangle::getLongueur() const { return longueur; }
int TRectangle::getLargeur() const { return largeur; }
void TRectangle::setLongueur(int l) { longueur = l; }
void TRectangle::setLargeur(int l) { largeur = l; }

TPoint TRectangle::GetPoint1() const { return getOrigine(); }

TPoint TRectangle::GetPoint2() const {
    return TPoint(getOrigine().getX() + longueur, getOrigine().getY() + largeur);
}

TRectangle operator*(int k, const TRectangle &r) {
    return TRectangle(k * r.getOrigine(), k * r.getLongueur(), k * r.getLargeur());
}

TRectangle operator*(const TRectangle &r, int k) {
    
    return operator*(k, r);
}

TRectangle operator+(const TPoint &p1, const TPoint &p2) {
    int longueur = p2.getX() - p1.getX();
    int largeur = p2.getY() - p1.getY();
    return TRectangle(p1, abs(longueur), abs(largeur));
}
