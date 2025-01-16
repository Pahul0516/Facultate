using Lab10.Domain;

namespace Lab10.Repository;

public class RepoMeci
{
    List<Meci> Meciuri = new List<Meci>();
    public Meci GetById(int id) { return Meciuri.FirstOrDefault(meci => meci.Id == id); }
    public IEnumerable<Meci> GetAll() { return Meciuri; }
    public void Add(Meci entity) { Meciuri.Add(entity); }
    public void Update(Meci entity)
    {
        var meciVechi = GetById(entity.Id);
        if (meciVechi != null)
            meciVechi.Echipa1 = entity.Echipa1;
            meciVechi.Echipa2 = entity.Echipa2;
            meciVechi.Data = entity.Data;
    }
    public void Delete(int id) { Meciuri.Remove(GetById(id)); }
}