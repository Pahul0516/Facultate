namespace Lab10.Domain;

public class TeamScoreDTO
{
    public string TeamName { get; set; }
    public int Score { get; set; }

    public TeamScoreDTO(string teamName, int score)
    {
        TeamName = teamName;
        Score = score;
    }
}