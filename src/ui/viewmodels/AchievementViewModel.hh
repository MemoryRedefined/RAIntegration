#ifndef RA_UI_ACHIEVEMENT_VIEWMODEL_H
#define RA_UI_ACHIEVEMENT_VIEWMODEL_H
#pragma once

#include "AssetViewModelBase.hh"

namespace ra {
namespace ui {
namespace viewmodels {

class AchievementViewModel : protected AssetViewModelBase
{
public:
    AchievementViewModel() noexcept;

    /// <summary>
    /// The <see cref="ModelProperty" /> for the achievement points.
    /// </summary>
    static const IntModelProperty PointsProperty;

    /// <summary>
    /// Gets the points for the achievement.
    /// </summary>
    int GetPoints() const { return GetValue(PointsProperty); }

    /// <summary>
    /// Sets the points for the achievement.
    /// </summary>
    void SetPoints(int nValue) { SetValue(PointsProperty, nValue); }

    /// <summary>
    /// The <see cref="ModelProperty" /> for the badge.
    /// </summary>
    static const StringModelProperty BadgeProperty;

    /// <summary>
    /// Gets the name of the badge associated to the achievement.
    /// </summary>
    const std::wstring& GetBadge() const { return GetValue(BadgeProperty); }

    /// <summary>
    /// Sets the name of the badge associated to the achievement.
    /// </summary>
    void SetBadge(const std::wstring& sValue) { SetValue(BadgeProperty, sValue); }

    /// <summary>
    /// Opens the file chooser to select a new badge image.
    /// </summary>
    void SelectBadgeFile();

    /// <summary>
    /// The <see cref="ModelProperty" /> for whether or not the emulator should be paused when the trigger is reset.
    /// </summary>
    static const BoolModelProperty PauseOnResetProperty;

    /// <summary>
    /// Gets whether or not the emulator should be paused when the trigger is reset.
    /// </summary>
    bool IsPauseOnReset() const { return GetValue(PauseOnResetProperty); }

    /// <summary>
    /// Sets whether or not the emulator should be paused when the trigger is reset.
    /// </summary>
    void SetPauseOnReset(bool nValue) { SetValue(PauseOnResetProperty, nValue); }

    /// <summary>
    /// The <see cref="ModelProperty" /> for whether or not the emulator should be paused when the achievement triggers.
    /// </summary>
    static const BoolModelProperty PauseOnTriggerProperty;

    /// <summary>
    /// Gets whether or not the emulator should be paused when the achievement triggers.
    /// </summary>
    bool IsPauseOnTrigger() const { return GetValue(PauseOnTriggerProperty); }

    /// <summary>
    /// Sets whether or not the emulator should be paused when the achievement triggers.
    /// </summary>
    void SetPauseOnTrigger(bool nValue) { SetValue(PauseOnTriggerProperty, nValue); }

    /// <summary>
    /// The <see cref="ModelProperty" /> for the trigger modification state.
    /// </summary>
    static const IntModelProperty TriggerProperty;

    /// <summary>
    /// Gets the trigger definition.
    /// </summary>
    const std::string& GetTrigger() const { return GetAssetDefinition(m_pTrigger); }
    
    /// <summary>
    /// Sets the trigger definition.
    /// </summary>
    void SetTrigger(const std::string& sTrigger) { SetAssetDefinition(m_pTrigger, sTrigger); }

private:
    AssetDefinition m_pTrigger;
};

} // namespace viewmodels
} // namespace ui
} // namespace ra

#endif RA_UI_ACHIEVEMENT_VIEWMODEL_H
