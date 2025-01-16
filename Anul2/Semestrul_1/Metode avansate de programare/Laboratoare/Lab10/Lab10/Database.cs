using Lab10.Domain;
using Lab10.Repository;

namespace Lab10;
using System;
using Npgsql;

class Database()
{
    private RepoElevi repoElevi;
    private  RepoEchipa repoEchipe;
    private RepoJucator repoJucator;
    private RepoMeci repoMeci;
    private NpgsqlConnection npgsqlConnection;
    
    public Database(RepoElevi repoElevi, RepoEchipa repoEchipe, RepoJucator repoJucator, RepoMeci repoMeci) : this()
    {
        this.repoElevi = repoElevi;
        this.repoEchipe = repoEchipe;
        this.repoJucator = repoJucator;
        this.repoMeci = repoMeci;
        
        string connString = "Host=localhost;" +
                            "Port=5432;" +
                            "Username=postgres;" +
                            "Password=Qwertyuiop12!;" +
                            "Database=NBA_DB";

        using (var conn = new NpgsqlConnection(connString))
        {
            npgsqlConnection = conn;
            try
            {
                npgsqlConnection.Open();
                Console.WriteLine("Connection successful!");
                load_data(conn);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }
        Console.WriteLine("Connection closed.");
    }
    void load_data(NpgsqlConnection conn) 
    {
        using (var cmd = new NpgsqlCommand("Select * from elev", conn))
        {
            var reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                Elev e = new Elev(reader.GetInt32(0), reader.GetString(1), reader.GetString(2));
                repoElevi.Add(e);
            }
            reader.Close();
        }
        using (var cmd = new NpgsqlCommand("Select * from echipa", conn))
        {
            var reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                Echipa e = new Echipa(reader.GetInt32(0), reader.GetString(1));
                repoEchipe.Add(e);
            }
            reader.Close();
        }
        using (var cmd = new NpgsqlCommand("Select * from meci", conn))
        {
            var reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                Meci m = new Meci(reader.GetInt32(0), repoEchipe.GetById(reader.GetInt32(1)),repoEchipe.GetById(reader.GetInt32(2)), reader.GetDateTime(3));
                repoMeci.Add(m);
            }
            reader.Close();
        }
        using (var cmd = new NpgsqlCommand("Select * from jucator", conn))
        {
            var reader = cmd.ExecuteReader();
            while (reader.Read())
            { 
                var id_jucator = reader.GetInt32(0);
                var nume = repoElevi.GetById(id_jucator).Name;
                var scoala = repoElevi.GetById(id_jucator).School;
                var id_meci = reader.GetInt32(1);
                var numarPuncteInscrise = reader.GetInt32(3);
                var tip = reader.GetString(4);
                var idEchipa = reader.GetInt32(2);
                var echipa = repoEchipe.GetById(idEchipa);
                if (tip != "Rezerva")
                {
                    JucatorActiv ja = new JucatorActiv(id_jucator, nume, scoala, echipa, id_meci, numarPuncteInscrise, tip, idEchipa);
                    repoJucator.Add(ja);
                }
                else
                {
                    Jucator j = new Jucator(id_jucator, nume, scoala, echipa);
                    repoJucator.Add(j);
                }
            }
            reader.Close();
        }
    }
}