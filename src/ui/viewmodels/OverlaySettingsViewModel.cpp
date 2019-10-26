#include "OverlaySettingsViewModel.hh"

#include "services\IConfiguration.hh"
#include "services\ServiceLocator.hh"

namespace ra {
namespace ui {
namespace viewmodels {

const BoolModelProperty OverlaySettingsViewModel::DisplayAchievementTriggerProperty("OverlaySettingsViewModel", "DisplayAchievementTrigger", true);
const BoolModelProperty OverlaySettingsViewModel::ScreenshotAchievementTriggerProperty("OverlaySettingsViewModel", "ScreenshotAchievementTrigger", false);
const BoolModelProperty OverlaySettingsViewModel::DisplayLeaderboardStartedProperty("OverlaySettingsViewModel", "DisplayLeaderboardStarted", true);
const BoolModelProperty OverlaySettingsViewModel::DisplayLeaderboardCanceledProperty("OverlaySettingsViewModel", "DisplayLeaderboardCanceled", true);
const BoolModelProperty OverlaySettingsViewModel::DisplayLeaderboardValueProperty("OverlaySettingsViewModel", "DisplayLeaderboardValue", true);
const BoolModelProperty OverlaySettingsViewModel::DisplayLeaderboardScoreboardProperty("OverlaySettingsViewModel", "DisplayLeaderboardScoreboard", true);
const StringModelProperty OverlaySettingsViewModel::ScreenshotLocationProperty("OverlaySettingsViewModel", "ScreenshotLocation", L"");

OverlaySettingsViewModel::OverlaySettingsViewModel() noexcept
{
    SetWindowTitle(L"Overlay Settings");
}

void OverlaySettingsViewModel::Initialize()
{
    const auto& pConfiguration = ra::services::ServiceLocator::Get<ra::services::IConfiguration>();
    SetDisplayAchievementTrigger(pConfiguration.IsFeatureEnabled(ra::services::Feature::AchievementTriggeredNotifications));
    SetScreenshotAchievementTrigger(pConfiguration.IsFeatureEnabled(ra::services::Feature::AchievementTriggeredScreenshot));
    SetDisplayLeaderboardStarted(pConfiguration.IsFeatureEnabled(ra::services::Feature::LeaderboardNotifications));
    SetDisplayLeaderboardCanceled(pConfiguration.IsFeatureEnabled(ra::services::Feature::LeaderboardCancelNotifications));
    SetDisplayLeaderboardValue(pConfiguration.IsFeatureEnabled(ra::services::Feature::LeaderboardCounters));
    SetDisplayLeaderboardScoreboard(pConfiguration.IsFeatureEnabled(ra::services::Feature::LeaderboardScoreboards));

    SetScreenshotLocation(pConfiguration.GetScreenshotDirectory());
}

void OverlaySettingsViewModel::Commit()
{
    auto& pConfiguration = ra::services::ServiceLocator::GetMutable<ra::services::IConfiguration>();

    pConfiguration.SetFeatureEnabled(ra::services::Feature::AchievementTriggeredNotifications, DisplayAchievementTrigger());
    pConfiguration.SetFeatureEnabled(ra::services::Feature::AchievementTriggeredScreenshot, ScreenshotAchievementTrigger());
    pConfiguration.SetFeatureEnabled(ra::services::Feature::LeaderboardNotifications, DisplayLeaderboardStarted());
    pConfiguration.SetFeatureEnabled(ra::services::Feature::LeaderboardCancelNotifications, DisplayLeaderboardCanceled());
    pConfiguration.SetFeatureEnabled(ra::services::Feature::LeaderboardCounters, DisplayLeaderboardValue());
    pConfiguration.SetFeatureEnabled(ra::services::Feature::LeaderboardScoreboards, DisplayLeaderboardScoreboard());

    std::wstring sLocation = ScreenshotLocation();
    if (!sLocation.empty() && sLocation.back() != '\\')
        sLocation.push_back('\\');

    pConfiguration.SetScreenshotDirectory(sLocation);

    pConfiguration.Save();
}

void OverlaySettingsViewModel::BrowseLocation() noexcept
{
    // TODO
}

} // namespace viewmodels
} // namespace ui
} // namespace ra